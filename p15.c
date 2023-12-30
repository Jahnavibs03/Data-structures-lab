//Develop a menu driven program to implement Binary Search tree with the following operations. i) Construction ii) Traversals( Pre, In and Post Order) iii) Searching a node by key and deleting if exists ( node to be deleted may be leaf or non- leaf with one child or two children
#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
    int data;
    struct tree *llink,*rlink;
}TREE;
TREE *create(int );
TREE *min(TREE *root);


TREE *insert(TREE *root,int key)//to insert a node
{
    if(root==NULL)
    return create(key);
    if(key<=root->data)
    root->llink= insert(root->llink,key);
    else
    root->rlink= insert(root->rlink,key);
    return root;
}

TREE *create(int key){     //this function is for insert operation
    TREE *node=(TREE*)malloc(sizeof(TREE));
    node->data=key;
    node->llink=node->rlink=NULL;
    return node;
}

//traversals
void inorder(TREE *root){
    if(root!=NULL){
        inorder(root->llink);
        printf("%d ",root->data);
        inorder(root->rlink);
    }
}

void preorder(TREE *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

void postorder(TREE *root){
    if(root!=NULL){
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d ",root->data);
    }
}

TREE *delete(TREE *root,int key){   //to delete a node
    if(root==NULL)
    return root;
    if(key<root->data)
    root->llink=delete(root->llink,key);
    else if(key>root->data)
    root->rlink=delete(root->rlink,key);
    else{
        if(root->llink==NULL){
            TREE *temp=root->rlink;
            free(root);
            return temp;
        }
        else if(root->rlink==NULL){
            TREE *temp=root->llink;
            free(root);
            return temp;
        }
        TREE *temp=min(root->rlink);
        root->data=temp->data;
        root->rlink=delete(root->rlink,temp->data);
    }
    return root;
}

TREE *min(TREE *root){     //this function is for delete
    TREE *temp=root;
    while(temp&&temp->llink!=NULL)
    temp=temp->llink;
    return temp;
}

void main(){
    TREE *root=NULL;
    int ch,n,key,val;
    printf("1.create tree\n2.preorder traversal\n3.inorder traversal\n4.postorder traversal\n5.delete a node\n0.exit\n");
    for(;;){
        printf("enter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
            printf("enter number of nodes required: ");
            scanf("%d",&n);
            for(int i=0;i<n;i++){
                printf("enter key value: ");
                scanf("%d",&key);
                root=insert(root,key);
            }
            break;
            case 2:
            printf("PREORDER: ");
            preorder(root);
            printf("\n");
            break;
            case 3:
            printf("INORDER: ");
            inorder(root);
            printf("\n");
            break;
            case 4:
            printf("POSTORDER: ");
            postorder(root);
            printf("\n");
            break;
            case 5:
            printf("enter a value to delete a node: ");
            scanf("%d",&val);
            root=delete(root,val);
            break;
            case 0:
            printf("THANKYOU\n");
            exit(0);
            default:
            printf("wrong choice\n");
            break;
        }
    }
}

