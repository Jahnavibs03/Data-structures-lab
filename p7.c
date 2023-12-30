//Implement circular single linked list to perform the following operations i) Insert by position ii) Delete rear iii) Delete Front iv) Search for an item by value Display the list contents after each operation
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

NODE *deletef(NODE *h){
  if(h==NULL){ 
  printf("empty!!!\n");
  return h;}
  NODE *tm=h;
  while(tm->link!=h)
  tm=tm->link;
  tm->link=h->link;
  tm=h;
  h=h->link;n--;
  free(tm);
  return h;
}

NODE *deleter(NODE *h){
  if(h==NULL){ 
  printf("empty!!!\n");
  return h;}
  NODE *tm=h,*pn=NULL;
  while(tm->link!=h){ 
  pn=tm;
  tm=tm->link;}
  pn->link=tm->link;
  free(tm);n--;
  return h;
}

NODE *insertp(NODE *h,int val,int pos){
  NODE *nn=getnode(val);
  NODE *tm=h,*pn=h;
  if(h==NULL){ 
    h=nn;n++;
    return h;}
  else if(pos>n||pos<1)
  printf("invalid position!!\n");
  else if(pos==1){
    nn->link=h; 
    while(tm->link!=h)
    tm=tm->link;
    tm->link=nn;
    h=nn;n++;
  }
  else{
    for(int i=1;i<pos-1;i++)
    tm=tm->link;
    nn->link=tm->link;
    tm->link=nn;n++;  
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
  printf("1.delete front\n2.delete rear\n3.insert by position\n4.search by position\n5.display\n0.exit\n");
  for(;;){
    printf("enter choice: ");
    scanf("%d",&ch);
    switch(ch){ 
    case 1:
    h=deletef(h);
    break;
    case 2:
    h=deleter(h);
    break;
    case 3:
    printf("enter value and position to insert: ");
    scanf("%d %d",&val,&pos);
    h=insertp(h,val,pos);
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
