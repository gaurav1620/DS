#include<stdio.h>
#include <stdlib.h>
//This stack uses the doubling array method 

struct ArrayStack{
	int top;
	int capacity;
	int size;
	char* arr;
};

typedef struct ArrayStack ArrayStack;

ArrayStack* CreateStack(){
	ArrayStack* as = malloc(sizeof(ArrayStack));
	if(!as){
		printf("Memory error !!\n");
		return NULL;
	}
	as->top = -1;
	as->capacity = 2;
	as->size = 0;
	as->arr = malloc(as->capacity * sizeof(char));

	return as;
}

_Bool isEmpty(ArrayStack**s){
	ArrayStack*tmp = *s;
	return tmp->top == -1;
}


void doubleArray(ArrayStack**s){
	ArrayStack* tmp = *s;
	tmp->capacity *= 2;
	tmp->arr = realloc(tmp->arr, tmp->capacity * sizeof(char));
}

void push(ArrayStack**s,char* inp){
	ArrayStack* tmp = *s;

	tmp->size ++;

	if(tmp->top == (tmp->capacity) - 1){
		doubleArray(s);
	}
	tmp->arr[++ tmp->top] = *inp;
}

char pop(ArrayStack**s){
	
	if(!isEmpty(s)){
		ArrayStack* tmp = *s;
		tmp->size --;
		return tmp->arr[tmp->top --];
	}
	printf("Empty!");
	return -1;
	
}

void display(ArrayStack**s){
	ArrayStack* tmp = *s;
	if(!tmp){
		printf("Memory error !");
		return;
	}
	if(tmp->top == -1){
		printf("Empty stack !!\n");
		return;
	}
	int top = tmp->top;
	printf("\nStack : \n");
	while(top > -1){
		printf("%c\n",tmp->arr[top]);
		top--;
	}

}

char top(ArrayStack**s){
	ArrayStack* tmp = *s;
	return tmp->arr[tmp->top];
}

int getPrecendace(char *x){
	char i = *x;
	if(i == '-' || i == '+'){

		return 1;
	}
	
	else if(i == '*' || i == '/'){
		
		return 2;
	}


	
}

void printPostfix(char inp[50]){
	ArrayStack* s = CreateStack();

	int l = 0;

	while(inp[l++]!= '\0');

	for(int i = 0;i < l;i++){
		char x = inp[i];

		if(x == '('){
			push(&s,&x);

		}
		else if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
			printf("%c",x);

		else if(x == ')'){
			while(top(&s) != '(' && !isEmpty(&s)){
				printf("%c",pop(&s));
			}
			if(top(&s) == '('){
				pop(&s);	
			}
			
		}else{// x is an operator 
			if(!isEmpty(&s)){
				while(s->arr[top(&s)] != '(' && getPrecendace(&s->arr[top(&s)]) <= getPrecendace(&x) && !isEmpty(&s)){
				//printf("check\n");
				printf("%c",pop(&s));
				}
			}
			if(s->arr[top(&s)] == '(')
				pop(&s);
			
			push(&s,&x);
		}

	}

	while(!isEmpty(&s)){

		if(s->arr[top(&s)] == '('){
			pop(&s);
		}
		printf("%c",pop(&s));
	}
	printf("\n");
	
}

//MAIN
int main (void){
	char inp[50];

	// printf("%c\n",'+');
	// printf("%c\n","+");
	// printf("%d\n",'+');
	// printf("%d\n","+");

	//Taking user input
	printf("\nEnter the Operation to convert it from infix to postfix : ");
	scanf("%s",inp);

	

	printPostfix(inp);
}