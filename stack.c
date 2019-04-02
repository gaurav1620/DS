#include <stdio.h>
#include <stdlib.h>


struct Node{
	int data;
	struct Node* link;
};

struct Node* top;

void push(){
	int data;
	printf("Enter the element to push : ");
	scanf("%d",&data);

	//create a new node temp and allocate size to it
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));

	if(!temp){
		printf("\n Stack Overflow");
		return;
	}
	//put the data in the temp field
	temp->data = data;

	//put top pointer reference to the temp link
	temp->link = top;

	//make temp as top of Stack
	top = temp;
}

_Bool isEmpty(){
	return top == NULL;
}

int topElement(){
	if(!isEmpty(top))
		return top->data;
	else
		return 420;
}

void pop(){
	struct Node* temp;

	if(top == NULL){
		printf("\n Stack is empty nothing to pop()");
		return;
	}else{
		//assign top to temp

		temp = top;
		printf("popped top element which is of the value %d",top->data);
		//assign second node to top
		top = top->link;

		//destroy the connection link
		temp->link = NULL;

		//release memory of the top node
		free(temp);

		return;
	}
}

void display(){
	struct Node* temp;

	//check for underflow
	if(top == NULL)
		printf("\n Stack is underflow.\n");
	else{
		temp = top;
		while(temp != NULL){
			printf("%d -> ",temp->data);
			temp = temp->link;
		}
	}
}

int main (void){
	int choice = 0;

	void printOptions(){
		printf("1.push() \n2.pop() \n3.topElemet() \n4.isEmpty() \n5.display() \n6.Display options. \n9.Exit\n");
	}

	printOptions();

	while(choice != 9){
		printf("\nEnter your choice: ");
		scanf("%d",&choice);

		switch(choice){
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			if(topElement() == 420)
				printf("The stack is Empty");
			else
				printf("%d",topElement());
			break;
		case 4:
			if(isEmpty())
				printf("Yes the stack is empty! ");
			else
				printf("NO the stack is not empty! ");
			break;
		case 5:
			display();
			break;
		case 6:
			printOptions();
			break;
		case 9:
			choice = 9;			

	}

	}
}