//Implement circular double linked list to perform the following operations i) Insert by order ii) Delete rear iii) Delete Front iv) Search for an item by position Display the list contents after each operation
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

NODE *deletef(NODE *h){
  if(h->r==h){ 
  printf("empty!!!\n");
  return h;}
  NODE *tm=h->r;
  tm->l->r=tm->r;
  tm->r->l=tm->l;
  h->data--;
  free(tm);
  return h;
}

NODE *deleter(NODE *h){
  if(h->r==h){ 
  printf("empty!!!\n");
  return h;}
  NODE *tm=h->l;
  tm->l->r=tm->r;
  tm->r->l=tm->l;
  h->data--;
  free(tm);
  return h;
}

NODE *inserto(NODE *h,int val){
  NODE *nn=getnode(val);
  NODE *tm=h;
  if(h->r==h){
    nn->r=h->r;
    nn->l=h;
    h->r=nn;
    h->l=nn;
    h->data++;
    return h;
  }
  while(tm->r!=h&&val>tm->r->data)
  tm=tm->r;
  nn->r=tm->r;
  nn->l=tm;
  tm->r->l=nn;
  tm->r=nn;
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

NODE *searchp(NODE *h,int pos){
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
  printf("value at position %d is %d\n",pos,tm->data);
}

void main(){
  NODE *h=(NODE*)malloc(sizeof(NODE));
  h->data=0;
  h->r=h->l=h;
  int val,pos,ch;
  printf("1.insert by order\n2.delete at rear\n3.delete at front\n4.search by position\n5.display\n0.exit\n");
  for(;;){
    printf("enter choice: ");
    scanf("%d",&ch);
    switch(ch){ 
    case 1:
    printf("enter value: ");
    scanf("%d",&val);
    h=inserto(h,val);
    break;
    case 2:
    h=deleter(h);
    break;
    case 3:
    h=deletef(h);
    break;
    case 4:
    printf("enter position to search: ");
    scanf("%d",&pos);
    searchp(h,pos);
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
