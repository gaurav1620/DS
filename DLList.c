#include <stdio.h>
#include <stdlib.h>

struct DLLNode{
	int data;
	struct DLLNode* before;
	struct DLLNode* next;
};

typedef struct DLLNode DLLNode;

DLLNode* head;




void delete(DLLNode** head,int position){
	if(position == 1){
		if(*head == NULL){
			printf("List is empty");
			return;
		}
		DLLNode* tmp;
		tmp = (DLLNode*)malloc(sizeof(DLLNode));
		tmp = *head;

		*head = tmp->next;
		free(tmp);
		return;
	}

	int k = 1;
	DLLNode *tmp,*var;
	var = (DLLNode*)malloc(sizeof(DLLNode));
	tmp = (DLLNode*)malloc(sizeof(DLLNode));
	tmp = *head;
	while(k < position-1&tmp->next != NULL){
		tmp = tmp->next;
		k++;
	}
	if(tmp->next->next == NULL){
		var = tmp->next;

		tmp->next = NULL;
		free(var);
		return;
	}
	var = tmp->next;
	tmp->next = tmp->next->next;
	tmp->next->before = tmp;
	free(var);
	return;



}
void insert(DLLNode** head,int inpData,int position){
	if(position == 1){
		if(*head == NULL){
			//*head = (DLLNode*)malloc(sizeof(DLLNode));

			DLLNode *var;
			var = (DLLNode*)malloc(sizeof(DLLNode));
			var->next = NULL;
			var->before = NULL;

			var->data = inpData;
			*head = var;
			return;
		}

		DLLNode* tmp;
		tmp = (DLLNode*)malloc(sizeof(DLLNode));
		tmp->next = *head;
		tmp->before = NULL;
		tmp->data = inpData;

		*head = tmp;
		return;
	}

	int k = 1;
	DLLNode *tmp,*var;
	var = (DLLNode*)malloc(sizeof(DLLNode));
	tmp = (DLLNode*)malloc(sizeof(DLLNode));
	tmp = *head;
	while(k < position-1&tmp->next != NULL){
		tmp = tmp->next;
		k++;
	}
	if(tmp->next == NULL){
		var->data = inpData;
		var->next = NULL;
		var->before = tmp;
		tmp->next = var;
		return;
	}
	var->before = tmp;
	var->next = tmp->next;
	var->data = inpData;
	tmp->next->before = var;
	tmp->next = var;
}

void push(DLLNode**head,int data){
	insert(head,data,1);
}

void displayList(DLLNode**head){
  DLLNode*temp;
  temp = *head;

  printf("\n_____________________________________\n");
  while(temp!=NULL){
    printf("%d->",temp->data);
    temp = temp->next;
  }
  printf("\n--------------------------------------\n");
}


int main(void){
	insert(&head,69,1);
	insert(&head,70,2);
	insert(&head,71,3);
	insert(&head,72,4);
	insert(&head,73,5);
	insert(&head,74,6);
	insert(&head,75,7);
	insert(&head,690,4);

	displayList(&head);

	delete(&head,8);

	displayList(&head);
}