//Implement circular single linked list to perform the following operations i) Insert front ii) Insert rear iii) Delete a node with the given key iv) Search for an item by position Display the list contents after each operation
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *link;
}NODE;
int n;

NODE*getnode(int val){
  NODE *nn=(NODE *)malloc(sizeof(NODE));
  nn->link=nn;
  nn->data=val;
  return nn;
}

NODE *insertf(NODE *h,int val){
  NODE *nn=getnode(val);
  n++;
  if(h==NULL){
    h=nn;
    return h;
  }
  nn->link=h;
  NODE *tm=h;
  while(tm->link!=h)
  tm=tm->link;
  tm->link=nn;
  h=nn;
  return h;
}

NODE *insertr(NODE *h,int val){
  NODE *nn=getnode(val);
  n++;
  if(h==NULL){
    h=nn;
    return h;
  }
  NODE *tm=h;
  while(tm->link!=h)
  tm=tm->link;
  nn->link=tm->link;
  tm->link=nn;
  return h;
}

NODE *deletek(NODE *h,int val){
  int i;
  if(h==NULL){
  printf("empty!!!!\n");
  return h;} 
    NODE *tm=h,*pn=NULL;
    for(i=0;i<n&&val!=tm->data;i++){ 
      pn=tm;
      tm=tm->link;}
    if(i==n)
    printf("key not found!!\n");
    else if(i==0){
       if(h->link==h) 
    h=NULL;
        else{ 
    tm=h;pn=h;
    while(tm->link!=h)
    tm=tm->link;
    tm->link=h->link;
    h=h->link;}
    n--;
    free(pn);
    }
    else{
      pn->link=tm->link;
      free(tm);
      n--;
    }
  return h;
}

void display(NODE *h){
  if(h==NULL)
  printf("empty!!!\n");
  else{
    NODE *tm=h;
    do{
      printf("%d ",tm->data);
      tm=tm->link;
    }while(tm!=h);
    printf("\n");
  }
}

void searchp(NODE *h,int pos){
  if(h==NULL)
  printf("empty!!!\n");
  else if(pos>n||pos<1)
  printf("invalid position!!\n");
  else{
    NODE *tm=h;
    for(int i=1;i<pos;i++)
    tm=tm->link;
    printf("value at position %d is %d\n",pos,tm->data);
  }
 }

void main(){
  NODE *h=NULL;
  int val,pos,ch;
  printf("1.insert front\n2.insert rear\n3.delete by key\n4.search by position\n5.display\n0.exit\n");
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
    printf("enter value: ");
    scanf("%d",&val);
    h=deletek(h,val);
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
