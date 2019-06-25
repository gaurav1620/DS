#include<stdio.h>
#include <stdlib.h>


struct Node{
	int data;
	struct Node* next; 
};

typedef struct Node Node;

void printList(Node** head);
Node* sortedMerge(Node* l,Node* r);
void splitListInTwo(Node* start,Node** l,Node** r);


void push(Node** head,int dataInp){
	Node * x = *head;
	if(x == NULL){
		x = (Node*)malloc(sizeof(Node));
		x->data = dataInp;
		x->next = NULL;
		*head = x;
		return;
	}

	Node* new = (Node*)malloc(sizeof(Node));

	new->data = dataInp;
	new->next = *head;
	*head = new;

}

void mergeSortLinkedList(Node** head){

	if(head == NULL){
		return;
	}

	Node* current = *head;

	if(current->next == NULL){
		return;
	}

	Node* l;
	Node* r;
	splitListInTwo(current,&l,&r);

	mergeSortLinkedList(&l);
	mergeSortLinkedList(&r);

	*head = sortedMerge(l,r);

	printf("\nMerge sort returns  : ");printList(head);printf("\n");
	return;

}

void splitListInTwo(Node* start,Node** a,Node** b){

	//printList(&start);

	Node* fast = start->next;
	Node* slow = start;



	while(fast!= NULL && fast->next!=NULL){
		fast = fast->next;
		
		if( fast->next != NULL){
			fast = fast->next;
			slow = slow->next;
		}
	}
	*b = slow->next;
	slow->next = NULL;
	*a = start;

	printf("Splitted in 2 halves : \n");
	printf("\t");printList(a);printf("\n");
	printf("\t");printList(b);printf("\n");
}

Node* sortedMerge(Node* l,Node* r){
	printf("\nSorted merge called for : ");printList(&l);printf("  AND  ");printList(&r);
	if(!l)
		return r;
	else if(!r)
		return l;

	Node* newHead = NULL;
	Node* cp = newHead;

	
		if(l->data <= r->data){
			newHead = l;
			newHead->next = sortedMerge(l->next,r);
		}else{
			newHead = r;
			newHead->next = sortedMerge(l,r->next);
		}
	printf("\nSorted merge returns : ");
	printList(&newHead);
	printf("\n");
	return newHead;
}

void printList(Node** head){
	Node* x = *head;
	while(x!=NULL){
		printf("%d -> ",x->data);
		x = x->next;
	}
	printf("NULL ");
}

int main(void){
	Node* head1 = NULL;

	push(&head1,1);
	push(&head1,2);
	push(&head1,3);
	push(&head1,4);
	push(&head1,5);
	push(&head1,6);
	push(&head1,7);
	push(&head1,8);
	push(&head1,9);
	push(&head1,10);
	push(&head1,11);
	push(&head1,14);


	printList(&head1);
	
	mergeSortLinkedList(&head1);

	printList(&head1);
}