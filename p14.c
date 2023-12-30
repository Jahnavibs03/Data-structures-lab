//Develop a menu driven program to implement Binary Search tree with the following operations. i) Construction ii) Traversals ( Pre, In and Post Order) iii) Searching a node by key and displaying its information along with its parent is exists, otherwise a suitable message. iv) Counting all types of nodes. v) Finding height

#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
    int data;
    struct tree *llink,*rlink;
}TREE;
TREE *create(int key);

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

//count non leaf nodes
int countnl(TREE *root){
    if(root==NULL||(root->llink==NULL&&root->rlink==NULL))
    return 0;
    return 1+countnl(root->llink)+countnl(root->rlink);
}

//count leaf nodes
int countl(TREE *root){
    if(root==NULL)
    return 0;
    if(root->llink==NULL&&root->rlink==NULL)
    return 1;
    else
    return countl(root->llink)+countl(root->rlink);
}

//search a node and print its info along with parent
int search(TREE *root,int key){
    if(root==NULL){
    printf("node not found\n");
    return 0;}
    if((root->llink!=NULL&&root->llink->data==key)||(root->rlink!=NULL&&root->rlink->data==key)){ 
    printf("value %d node found ,its parent node is %d\n",key,root->data);
    return 1;}
    if(key<root->data)
    search(root->llink,key);
    else
    search(root->rlink,key);
}

//find height of node
int height(TREE *root){    
    if(root==NULL||(root->llink==NULL&&root->rlink==NULL))
    return 0;
    else{
        int l=height(root->llink);
        int r=height(root->rlink);
        if(l>r)
        return (l+1);
        else
        return (r+1);
    }
}

void main(){
    TREE *root=NULL;
    int ch,n,key,val;
    printf("1.create tree\n2.preorder traversal\n3.inorder traversal\n4.postorder traversal\n5.count all types of nodes\n6.find height\n7.search value\n0.exit\n");
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
            printf("number of leaf nodes: %d\n",countl(root));
            printf("number of non-leaf nodes: %d\n",countnl(root));
            break;
            case 6:
            printf("height of the tree is: %d\n",height(root));
            break;
            case 7:
            printf("enter a value to search: ");
            scanf("%d",&val);
            key=search(root,val);
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
