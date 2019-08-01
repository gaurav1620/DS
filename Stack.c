#include<stdio.h>
#include <stdlib.h>
//This stack uses the doubling array method 

struct ArrayStack{
	int top;
	int capacity;
	int* arr;
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
	as->arr = malloc(as->capacity * sizeof(int));

	return as;
}

_Bool isEmpty(ArrayStack**s){
	ArrayStack*tmp = *s;
	return tmp->top == -1;
}


void doubleArray(ArrayStack**s){
	ArrayStack* tmp = *s;
	tmp->capacity *= 2;
	tmp->arr = realloc(tmp->arr, tmp->capacity * sizeof(int));
}

void push(ArrayStack**s,int inp){
	ArrayStack* tmp = *s;
	if(tmp->top == (tmp->capacity) - 1){
		doubleArray(s);
	}
	tmp->arr[++ tmp->top] = inp;
}

int pop(ArrayStack**s){
	
	if(!isEmpty(s)){
		ArrayStack* tmp = *s;
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
		printf("%d\n",tmp->arr[top]);
		top--;
	}

}

int top(ArrayStack**s){
	ArrayStack* tmp = *s;
	return tmp->arr[tmp->top];
}

//MAIN
int main (void){
	ArrayStack* s = CreateStack();

	 push(&s,1);
	push(&s,2);
	push(&s,3);
	push(&s,4);
	push(&s,5);
	push(&s,6);

	display(&s);

	pop(&s);

	display(&s);
}