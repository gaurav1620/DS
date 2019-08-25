#include<stdio.h>
#include<stdlib.h>

//Binary tree Node
struct node{
    int val;
    struct node *l;
    struct node *r;
};
typedef struct node node;

//QUEUE node
struct queue{
    node* val[100];
    int size;
    int front;
    int back;
};
typedef struct queue queue;



//FUNCTIONS

int check_Whether_Tree_Is_A_Full_Binary_Tree(node* root);
node* lca(node*root, int a, int b);
node* newN(int data);
int height(node* root);
void inOrderTraversal(node* root);
void preOrderTraversal(node* root);



void levelOrderTraversal(node* root);
void printLevel(node* root,int level);

void levelOrderTraversalUsingQueue(node* root);

node* constructTreeFromInorderAndPreorder(int arr1[],int arr2[],int l1,int l2);


//QUEUE
queue* initQueue();
void enqueue(queue* q,node* data);
node* dequeue(queue* q);
void printQueue(queue* q);

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

    printf("preOrderTraversal : ");
    preOrderTraversal(root);
    printf("\n");
    //arr = {1 2 4 8 9 5 10 11 3 6 12 13 7 14 15}

    printf("inOrderTraversal : ");
    inOrderTraversal(root);
    printf("\n");
    //arr = {8 4 9 2 10 5 11 1 12 6 13 3 14 7 15}

    int preArr[] = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15};
    int inArr[]  = {8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15};

    inOrderTraversal(constructTreeFromInorderAndPreorder(preArr,inArr,0,14)); 

    // printf("%d",height(root));
    // printf("\n\n%d\n",lca(root,9,11)->val);

/*
    if(check_Whether_Tree_Is_A_Full_Binary_Tree(root) == 1){
        printf("\nTree is a Full Binary tree !!\n");
    }
    else{
        printf("\nTree is a NOT Full Binary tree.\n");
    }
*/
/*
    //LEVEL ORDER TRAVERSAL
    printf("LEVEL ORDER TRAVERSAL!! : \n");
    levelOrderTraversal(root);
*/


//    levelOrderTraversalUsingQueue(root);

}


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
static int debugIndex = 0;
void inOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root->l);
    printf("\n%d : %d",debugIndex++,root->val);
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

void printLevel(node* root,int level){
    if(root == NULL) return ;
    if(level == 1){
        printf("%d ",root->val);
        return;
    }else{
        printLevel(root->l,level - 1);
        printLevel(root->r,level - 1);
    }
}

void levelOrderTraversal(node* root){
    int h = height(root);
    for(int i = 1 ;i <= h;i++){
        printLevel(root,i);
    }
}

void levelOrderTraversalUsingQueue(node* root){
    if(root == NULL){
        return;
    }
    else{
        printf("The level order traversal using queue is : \n");
        queue* q = initQueue();
        node* tmp = root;

        while(tmp){
            printf("%d ",tmp->val);

            if(tmp->l) enqueue(q,tmp->l);
            if(tmp->r) enqueue(q,tmp->r);

            tmp = dequeue(q);
        }
        printf("\n");
    }
}


static int preOrderIndex = 0;
node* constructTreeFromInorderAndPreorder(int pre[], int in[], int start, int end){
    // pre arr = {1 2 4 8 9 5 10 11 3 6 12 13 7 14 15}
    // in  arr = {8 4 9 2 10 5 11 1 12 6 13 3 14 7 15}
    if(start > end) return NULL;
    else if(start == end){
        node* tmp = newN(pre[preOrderIndex]);
        preOrderIndex++;
        return tmp;
    }

    node* tmp = newN(pre[preOrderIndex]);
    preOrderIndex++;
    printf("\n\n\nCreated a new Node : %d\n",tmp->val);
    
    int currPos;
    for(int i = start;i < end;i++){
        if(in[i] == pre[preOrderIndex-1]){

            currPos = i;
            printf("currElement : %d , curr pos : %d , preOrderIndex : %d\n",in[i],i,preOrderIndex -1);
            break;
        } 
    }

    printf("LEFT : start : %d, end : %d\n\n",start,end- currPos - 1);
    
    tmp->l = constructTreeFromInorderAndPreorder(pre, in, start,currPos - 1);
    printf("RIGHT : start : %d, end : %d\n",start + currPos + 1, end);
    tmp->r = constructTreeFromInorderAndPreorder(pre, in,currPos + 1, end );
    return tmp;
}

//QUEUE
//   __ _ _   _  __ _ _   _  ___ 
//  / _` | | | |/ _` | | | |/ _ \
// | (_| | |_| | (_| | |_| |  __/
//  \__, |\__,_|\__, |\__,_|\___|
//     |_|         |_|           
queue* initQueue(){
    queue* q = (queue*)malloc(sizeof(queue*));
    q->size = 0;
    q->front = -1;
    q->back = -1;
    return q;
}
void enqueue(queue* q,node* data){
    if(q->front == -1){
        q->front = 0;
        q->back = 0;
        q->size = 1;
        q->val[q->back] = data;
        //printf(" Enqueuing %d \n",q->val[q->back]->val);
        return;
    }else{
        q->size++;
        q->back++;
        q->val[q->back] = data;
        //printf(" Enqueuing %d \n",q->val[q->back]->val);
        return;
    }
}

node* dequeue(queue* q){

    if(q->size == 0)return NULL;
    else{
        q->size--;
        //q->front++;
        //printf(" Dequeuing %d \n",q->val[q->front]->val);
        return q->val[q->front++];
    }
}

void printQueue(queue* q){
    printf("QUEUE is as follows : \n");
    for(int i = q->front;i <= q->back;i++){
        printf("%d <- ",q->val[i]->val);
    }
    printf("\n");
}
