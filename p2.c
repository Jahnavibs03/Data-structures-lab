//Develop a menu driven program to implement the following operations on an array of integers with dynamic memory allocation. i) Insert by position ii) Delete by position iii) Insert by key iv) Delete by key v) Insert by order vi) Search by key vii) Search by position viii) Reverse the contents.

#include<stdio.h>
#include<stdlib.h>
int n;
int searchk(int *a,int key);

void read(int *a){
    printf("enter values: ");
    for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
}

void display(int *a){
    printf("elements are: \n");
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        printf("\n");
}
}

void insertp(int *a,int pos,int val){
if(pos<=n&&pos>=1){ 
  n++;a=(int *)realloc(a,n*sizeof(int));
for(int i=n;i>=pos-1;i--){
    a[i+1]=a[i];
}a[pos-1]=val;}
else
printf("invalid position!!\n");
}

void deletep(int *a,int pos){
if(pos<=n&&pos>=1){ 
for(int i=pos-1;i<n;i++){
    a[i]=a[i+1];
}n--;a=(int *)realloc(a,n*sizeof(int));}
else
printf("invalid position!!\n");
}

void insertk(int a[],int val){
   int pos=searchk(a,val);
   if(pos==0)
   printf("not found!!\n");
   else
   insertp(a,pos,val);
}

void deletek(int *a,int val){
   int pos=searchk(a,val);
   if(pos==0)
   printf("not found!!\n");
   else
   deletep(a,pos);
}   

int searchk(int *a,int key){
    for(int i=0;i<n;i++)
        if(a[i]==key)
            return (i+1);
    return 0;
}

void searchp(int *a,int pos){
    if(pos<=n&&pos>=1)
        printf("value at %d position is %d\n",pos,a[pos-1]);
    else
    printf("invalid position\n");
}

void inserto(int *a,int val){
    int t;n++;a=(int *)realloc(a,n*sizeof(int));
    a[n-1]=val;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

void reverse(int *a){
     int temp;
    for(int i = 0; i<n/2; i++){
        temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }
}
void main(){ 
    int *a;
    int choice,pos,val,key;
    printf("1.read\n2.display\n3.insert by position\n4.delete by position\n5.insert by key\n6.delete by key\n7.search value\n8.search position\n9.reverse\n10.insert by order\n0.exit\n");
    for(;;){
      printf("enter choice: ");scanf("%d",&choice);
                switch(choice){
                    case 1:
                    printf("enter number of values required: ");
                    scanf("%d",&n);
                    a=(int*)malloc(n*sizeof(int));
                    read(a);
                    break;
                    case 2:
                    display(a);
                    break;
                    case 3:
                    printf("enter position and value to insert:");
                    scanf("%d %d",&pos,&val);
                    insertp(a,pos,val);
                    break;
                    case 4:
                    printf("enter position to delete:");
                    scanf("%d",&pos);
                    deletep(a,pos);
                    break;
                    case 5:
                    printf("enter key after which insertion should be done:");
                    scanf("%d",&key);
                    printf("enter value to insert");
                    scanf("%d",&val);
                    insertk(a,val);
                    break;
                    case 6:
                    printf("enter value to delete:");
                    scanf("%d",&val);
                    deletek(a,val);
                    break;
                    case 7:
                    printf("enter value to search:");
                    scanf("%d",&val);
                    pos=searchk(a,val);
                    if(pos==0)
                    printf("not found\n");
                    else
                    printf("%d found at position %d\n",val,pos);
                    break;
                    case 8:
                    printf("enter position to search:");
                    scanf("%d",&pos);
                    searchp(a,pos);
                    break;
                    case 9:
                    reverse(a);
                    break;
                    case 10:
                    printf("enter value to insert:");
                    scanf("%d",&val);
                    inserto(a,val);
                    break;
                    case 0:
                    printf("---------THANKYOU---------\n");
                    exit(0);
                    default:
                    printf("wrong choice\n");
                    break;}}}
