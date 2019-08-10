#include<stdio.h>
#include<stdlib.h>


struct node{
    int val;
    struct node *l;
    struct node *r;
};
typedef struct node node;



node* newN(int data){
    node *tmp = (node*)malloc(sizeof(node*));
    tmp->val = data;
    tmp->l = NULL;
    tmp->r = NULL;

    return tmp;
}

//Left data right
void inOrderTraversal(node* root){
    if(root == NULL){
        //printf("EMPTY !!\n");
        return;
    }
    inOrderTraversal(root->l);
    printf("%d ",root->val);
    inOrderTraversal(root->r);
}

//data left right
void preOrderTraversal(node* root){
    if(root == NULL){
        //printf("EMPTY !!\n");
        return;
    }
    printf("%d ",root->val);
    preOrderTraversal(root->l);
    preOrderTraversal(root->r);
}

//My sphegetti code
node* insertBst(node* root,int data){
    if(root == NULL) return root = newN(data);

    else if(root->l == NULL && root->val > data){
        node* tmp = newN(data);
        root->l = tmp;

        return root;
    }
    else if(root->r == NULL && root->val < data){
        node* tmp = newN(data);
        root->r = tmp;

        return root;
    }
    else if(root->val < data) return insertBst(root->r,data);
    else if(root->val > data) return insertBst(root->l,data);
}

int globalcounter = 0;

node* searchBst(node* root,int data){
    printf("chexx\n");
    
    if(root->val == data) return root;
    else if(root->val > data) return searchBst(root->l,data);
    else return searchBst(root->r,data);
}

//GFG copied
node* insertBstGFG(node* root,int data){
    if(root == NULL) return root = newN(data);
    else if(root->val < data) root->r = insertBstGFG(root->r,data);
    else if(root->val > data) root->l = insertBstGFG(root->l,data);

    return root;
}

int main (){
/*
                        8
                    /       \
                    2       11
                    \       /   \
                    4       9   13
                    /   
                    3
*/
    node *root = newN(8);
    //insertBst(root,8);


    // insertBst(root,2);
    // insertBst(root,11);
    // insertBst(root,4);
    // insertBst(root,9);
    // insertBst(root,3);
    // insertBst(root,13);


    insertBstGFG(root,2);
    insertBstGFG(root,11);
    insertBstGFG(root,4);
    insertBstGFG(root,9);
    insertBstGFG(root,3);
    insertBstGFG(root,13);

    preOrderTraversal(root);
    printf("\n");

    int searchElement = 13; 
    printf("found %d in the above number of \"checkx\"  traversals\n",searchBst(root,searchElement)->val);
}