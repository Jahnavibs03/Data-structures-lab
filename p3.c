//Implement circular single linked list to perform the following operations i) Insert by order ii ) Delete by position iii) Search for an item by key Display the list contents after each operation

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

NODE *inserto(NODE *h,int val){
  NODE *tm=h;
  NODE *nn=getnode(val);
  if(h==NULL)
  h=nn;
  else if(val<h->data){
    nn->link=h;
    while(tm->link!=h)
    tm=tm->link;
    tm->link=nn;
    h=nn;
  }
  else{
    while(tm->link!=h&&val>tm->link->data)
    tm=tm->link;
    nn->link=tm->link;
    tm->link=nn;
  }
  n++;
  return h;
}

NODE *deletep(NODE *h,int pos){
  NODE *tm=h,*pn=h;
  if(h==NULL)
    printf("empty!!!!\n");
  else if(pos>n||pos<1)
  printf("invalid position!!\n");
  else if(pos==1){
    if(h->link==h) 
    h=NULL;
    else{ 
    while(tm->link!=h)
    tm=tm->link;
    tm->link=h->link;
    h=h->link;}
    n--;
    free(pn);
  }
  else{
    for(int i=1;i<pos-1;i++)
    tm=tm->link;
    pn=tm->link;
    tm->link=pn->link;
    n--; 
    free(pn);  
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

void searchk(NODE *h,int val){
  if(h==NULL)
  printf("empty!!!\n");
  else{
    NODE *tm=h;
    for(int i=0;i<n;i++){ 
    if(tm->data==val){
      printf("%d found at position %d\n",val,i+1);
      return;
    }
  }
  printf("not found!!\n");
  }
}

void main(){
  NODE *h=NULL;
  int val,pos,ch;
  printf("1.create ordered list\n2.delete by key\n3.search by key\n4.display\n0.exit\n");
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
    printf("enter position to delete: ");
    scanf("%d",&pos);
    h=deletep(h,pos);
    break;
    case 3:
    printf("enter value to search: ");
    scanf("%d",&val);
    searchk(h,val);
    break;
    case 4:
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
