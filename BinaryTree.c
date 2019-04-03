#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;

struct node* newNode(int InpData){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->data = InpData;
    tmp->left = NULL;
    tmp->right = NULL;

    return(tmp);
}

int main(void){
    node *root = newNode(5);
    root->left = newNode(6);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(9);
    root->right->left = newNode(10);
    root->right->right = newNode(11);

    printf("%d\n",root->left->right->data);

}
