#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *previous;
	
};
typedef struct node node;
struct queue{
	int count;
	node *first;
	node *last; 
};
typedef struct queue queue;

void intitalize(queue *q){
	q->count = 0;
	q->first = NULL;
	q->last = NULL;
}

int isEmpty(queue *q){
	if(((q->first == NULL) && (q->last == NULL))){
		
		return 0;
	}
	else{
		
		return 1;
	}
}

void enqueue(queue *q){
	printf("Enter element to be added : ");
	int tempVal;
	scanf("%d",&tempVal);
	if(isEmpty(q) == 1){
		node *tmp;
		tmp = malloc(sizeof(node));
		tmp->val = tempVal;
		tmp->previous = NULL;
		q->last->previous = tmp;
		q->last = tmp;
		q->count++;
		printf("Allocated!!\n");
		return;
	}
	else{
		node *tmp;
		tmp = malloc(sizeof(node));
		tmp->val = tempVal;
		tmp->previous = NULL;
		q->first = q->last = tmp;
		q->count++;
		printf("Allocated!!\n");
		return;
	}

}

int dequeue(queue *q){
	node *tmp;
	int n = q->first->val;
	tmp = q->first;
	q->first = q->first->previous;
	free(tmp);
	return (n);
}

void display(queue *q){
	if(q->first == NULL){
		printf("NULL queue!!");
	}
	else{
		printf("\nFirst- ");
		node *tmp;
		tmp = q->first;
		while(tmp != NULL){
			printf("%d<-",tmp->val);
			tmp = tmp->previous;
		}
	}
	printf(" -Last\n");
}

int main(void){

	queue *q;
	q = malloc(sizeof(queue));
	intitalize(q);
	// enqueue(q,5);
	// enqueue(q,6);
	// enqueue(q,7);
	// enqueue(q,8);
	// enqueue(q,9);
	// enqueue(q,10);

	// printf("Before dequeing!\n");
	// display(q);
	// dequeue(q);
	

	// printf("\nAfter dequeue:!\n");
	// display(q);

	void printOptions(){
		printf("\n1. Enqueue \n2. Dequeue \n3. DisplayQueue \n4. Check If Empty \n5. Show Options \n9. Quit\n");
	}
	int choice = 0;
	printOptions();
	
	while(choice != 9){
		printf("Enter choice :(press 5 for options)");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				enqueue(q);
				break;
			case 2:
				dequeue(q);
				break;
			case 3:
				display(q);
				break;
			case 4:
				if(isEmpty(q) == 0)
					printf("Is Empty\n");
				else
					printf("Not empty!!\n");
				break;
			case 5:
				printOptions();
				break;
			case 9:
				choice = 9;
				
				break;				
		}

	}
}