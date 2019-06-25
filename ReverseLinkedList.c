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

// NOT UNDERSTOOD TILL NOW LO COPIED FROM GFG
void recursiveReverseList(Node**head){

	Node* first;
	Node* rest;
	if(*head == NULL){
		return;
	}
	
	first = *head;
	rest = first->next;

	if(rest==NULL)
		return;

	
	recursiveReverseList(&rest);
	first->next->next = first;
	first->next = NULL;

	*head = rest;
	return;

}
Node* iterativeReverseList(Node*head){

	Node* tmp = head;
	Node* nxt;
	Node* before = NULL;
	while(tmp!=NULL){
		nxt = tmp->next;
		tmp->next = before;
		before = tmp;
		tmp = nxt;
	}
	return before;

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
	recursiveReverseList(&head);
	printList(&head);
}