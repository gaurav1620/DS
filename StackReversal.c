#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int data;
	struct node *down;

};
typedef struct node node;

int count = 0;

node* top;
void push(int var){
	if(top == NULL){

		top = (node*)malloc(sizeof(node));
		top->down == NULL;
		top->data = var;
		printf("Pushing the first element %d\n",top->data);
	}
	else{
		node *tmp;
		tmp = (node*)malloc(sizeof(node));
		tmp->down = top;
		tmp->data = var;
		top = tmp;
		printf("Pushing on top - %d\n",top->data);
	}
	count++;
}

int pop(){
	if(top != NULL){
		node *tmp;
		tmp = (node*)malloc(sizeof(node));
		tmp = top->down;
		int f = top->data;
		printf("Popped element data -: %d\n",top->data);
		free(top);
		top = tmp;
		return f;
	}else{
		printf("The stack is empty cannot pop\n");
		return -1;
	}
}

void display(){
	node *top1;
	top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
 	printf("TOP  ");
    while (top1 != NULL)
    {
        printf("%d ", top1->data);
        top1 = top1->down;
    }
    printf("   Bottom\n");
}

_Bool isEmpty(){
	return top == NULL;
}

void insetAtBottom(int d){
	if(top == NULL){
		push(d);
	}
	else{
		printf("Insert at bottom called for %d\n",d);
		int tmp = top->data;
		pop();
		insetAtBottom(d);
		push(tmp);
	}

}
void reverse(){
	if(top != NULL){
		int tmp = top->data;
		pop();
		reverse();
		insetAtBottom(tmp);
	}
}

int main(void){

	push(4);
	push(3);
	push(2);
	push(1);

	display();

	reverse();
	display();
}
