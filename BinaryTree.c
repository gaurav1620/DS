#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *l;
    struct node *r;
};
typedef struct node node;

//Func to check weather a tree is a full tree or not (PS A full tree's nodes have either no or two children)
int check_Whether_Tree_Is_A_Full_Binary_Tree(node* root){
    if(root->l == NULL && root->r == NULL) return 1;
    else if(root->l == NULL || root->r == NULL) return 0;
    else {
        return check_Whether_Tree_Is_A_Full_Binary_Tree(root->l) && check_Whether_Tree_Is_A_Full_Binary_Tree(root->r)? 1:0;
    }
}

//This lca is not for BST . as for a BST we can easily get O(h) time for searching any element.
node* lca(node*root, int a, int b){

    if(root == NULL) return NULL;
    if(root->val == a || root->val == b) return root;

    node *le = lca(root->l,a,b);
    node *ri = lca(root->r,a,b);

    if(le && ri) return root;
    return le != NULL ?le:ri;
}

node* newN(int data){
    node *tmp = (node*)malloc(sizeof(node*));
    tmp->val = data;
    tmp->l = NULL;
    tmp->r = NULL;

    return tmp;
}

int height(node* root){
    if(root == NULL){
        return 0;
    }
    else if(root->l == NULL && root->r ==NULL){
        return 1;
    }
    else if(height(root->l) > height(root->r)){
        return height(root->l)+1;
    }
    return height(root->r) +1;
}




//Left data right
void inOrderTraversal(node* root){
    if(root == NULL){
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

int main (){

    node *root = newN(1);

    node *l1 = newN(2);
    node *r1 = newN(3);


    node *ll2 = newN(4);
    node *lr2 = newN(5);
    node *rl2 = newN(6);
    node *rr2 = newN(7);

    node *lll3 = newN(8);
    node *llr3 = newN(9);
    node *lrl3 = newN(10);
    node *lrr3 = newN(11);
    node *rll3 = newN(12);
    node *rlr3 = newN(13);
    node *rrl3 = newN(14);
    node *rrr3 = newN(15);

    //Assignments
    root->l = l1;
    root->r = r1;

    l1->l = ll2;
    l1->r = lr2;
    r1->l = rl2;
    r1->r = rr2;

    ll2->l = lll3;
    ll2->r = llr3;
    lr2->l = lrl3;
    lr2->r = lrr3;
    rl2->l = rll3;
    rl2->r = rlr3;
    rr2->l = rrl3;
    rr2->r = rrr3;

    //printf("%d",root->l->r->l->val);
    preOrderTraversal(root);
    printf("\n");
    printf("%d",height(root));
    printf("\n\n%d\n",lca(root,9,11)->val);

    if(check_Whether_Tree_Is_A_Full_Binary_Tree(root) == 1){
        printf("\nTree is a Full Binary tree !!\n");
    }
    else{
        printf("\nTree is a NOT Full Binary tree.\n");
    }
}