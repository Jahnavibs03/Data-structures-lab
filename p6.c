//Implement circular double linked list to perform the following operations i) Insert front ii) Insert rear iii) Delete kth node iv) Search for an item by value. Display the list contents after each operation
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *l,*r;
}NODE;

NODE*getnode(int val){
  NODE *nn=(NODE *)malloc(sizeof(NODE));
  nn->l=nn->r=nn;
  nn->data=val;
  return nn;
}

void display(NODE *h){
  if(h->r==h){ 
  printf("empty!!!\n");
  return;}
  NODE *tm=h->r;
  while(tm!=h){
    printf("%d ",tm->data);
    tm=tm->r;
  }
  printf("\n");
}

NODE *insertf(NODE *h,int val){
  NODE *nn=getnode(val);
  nn->r=h->r;
  nn->l=h;
  h->r->l=nn;
  h->r=nn;
  h->data++;
  return h;
}

NODE *insertr(NODE *h,int val){
  NODE *nn=getnode(val);
  nn->r=h;
  nn->l=h->l;
  h->l->r=nn;
  h->l=nn;
  h->data++;
  return h;
}

NODE *deletep(NODE *h,int pos){
  if(h->r==h){ 
  printf("empty!!!\n");
  return h;}
  if(pos>h->data||pos<1){
    printf("invalid position!!\n");
    return h;
  }
  NODE *tm=h->r;
  for(int i=1;i<pos;i++)
  tm=tm->r;
  tm->l->r=tm->r;
  tm->r->l=tm->l;
  h->data--;
  free(tm);
  return h;
}

void searchk(NODE *h,int val){
  if(h->r==h){ 
  printf("empty!!!\n");
  return;}
  NODE *tm=h->r;
  int i=1;
  while(tm!=h&&tm->data!=val){ 
  tm=tm->r;
  i++;}
  if(tm==h)
  printf("not found!!\n");
  else
  printf("%d found at position %d\n",val,i);
}

void main(){
  NODE *h=(NODE*)malloc(sizeof(NODE));
  h->data=0;
  h->r=h->l=h;
  int val,pos,ch;
  printf("1.insert at front\n2.insert at rear\n3.delete by position\n4.search by position\n5.display\n0.exit\n");
  for(;;){
    printf("enter choice: ");
    scanf("%d",&ch);
    switch(ch){ 
    case 1:
    printf("enter value: ");
    scanf("%d",&val);
    h=insertf(h,val);
    break;
    case 2:
    printf("enter value: ");
    scanf("%d",&val);
    h=insertr(h,val);
    break;
    case 3:
    printf("enter position to delete: ");
    scanf("%d",&pos);
    h=deletep(h,pos);
    break;
    case 4:
    printf("enter value to search: ");
    scanf("%d",&val);
    searchk(h,val);
    break;
    case 5:
    display(h);
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
