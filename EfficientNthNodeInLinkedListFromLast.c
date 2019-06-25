#include<stdio.h>
#include <stdlib.h>


struct Node{
	int data;
	struct Node* next; 
};

typedef struct Node Node;

Node* push(Node** head,int dataInp){
	Node* new = (Node*)malloc(sizeof(Node));

	new->data = dataInp;
	new->next = *head;
	*head = new;

}


//THIS METHOD HAS TIME O(N^2) 
// Node* getNthElementFromLast(Node**head,int n){
// 
// 	Node* temp = *head;

// 	int i = 0;
// 	for(;temp!=NULL;temp = temp->next){
// 		i++;
// 	}
// 	//now i is the length and we have to get the n-i th element;

// 	temp = *head;
// 	for(int j = 0;j < i-n;j++){
// 		temp = temp->next;
// 	}
// 	printf("%d\n",temp->data );
// 	return temp;
// }


//This only requires one iteration and thus has time complexicity O(n)
Node* EfficientGetNthElementFromLast(Node**head,int n){
	Node* forward = *head;
	Node* back = *head;
	int i = 0;
	for(;(i < n) && (forward!= NULL);i++){
		forward = forward->next;
	}

	//If less elements are there in the list
	if(i < n && forward->next == NULL){
		printf("Not enough elements in the list to get %d th element\n",n);
		return *head;
	}

	while(forward!=NULL){
		forward = forward->next;
		back = back->next;
	}

	printf("the %d th element from end is %d\n",n,back->data);
	return back;

}

void printList(Node** head){
	Node* x = *head;
	while(x!=NULL){
		printf("%d -> ",x->data);
		x = x->next;
	}
	printf("NULL \n");
}

int main(void){
	Node* head = NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);
	push(&head,7);
	push(&head,8);
	push(&head,9);
	push(&head,10);
	push(&head,11);
	push(&head,14);


	printList(&head);
	EfficientGetNthElementFromLast(&head,12);
}