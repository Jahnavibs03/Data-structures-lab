//Develop a menu driven program to implement the following types of Queues by allocating memory dynamically. i) Circular Queue ii) Priority Queue
#include <stdio.h>
#include <stdlib.h>
int n = 0,max_size=3;

typedef struct queue
{
  int *queue;
  int front, rear;
}QUEUE;

QUEUE insert(QUEUE Q, int item)
{
  if(n==max_size)
  {
    printf("Queue overflow\nreallocating memory\n");
    max_size++;
    Q.queue=(int*)realloc(Q.queue,max_size*sizeof(int));
  }
    Q.rear = (Q.rear + 1) % max_size;
    Q.queue[Q.rear] = item;
    if (Q.front == -1)
      Q.front = 0;
    n = n + 1;
  return Q;
}

QUEUE delete (QUEUE Q)
{
  int item;
  if (n==0)
  {
    printf("Queue is empty\n");
  }
  else
  {
    item = Q.queue[Q.front];
    Q.front = (Q.front + 1) % max_size;
    n--;
    printf("Deleted item is %d\n", item);
  }
  return Q;
}

void display(QUEUE Q)
{
  int i, j;
  if (n==0)
  {
    printf("Queue empty\n");
    return;
  }
  printf("Contents are :\n");
  j = Q.front;
  for (i = 1; i <= n; i++)
  {
    printf("Q[%d]=%d\t", j, Q.queue[j]);
    j = (j + 1) % max_size;
  }printf("\n");
}


QUEUE ins(QUEUE Q,int ele)
{
  int j;
   if (Q.rear == max_size - 1){ 
    printf("Queue overflow\nreallocating memory\n");
    max_size++;
    Q.queue=(int*)realloc(Q.queue,max_size*sizeof(int));}
    j = Q.rear;
   while (j >= 0 && ele <Q.queue[j]) {
    Q.queue[j + 1] =Q.queue[j];
     j--;  }
    Q.queue[j + 1] = ele;
    Q.rear++;
  return Q;
}

QUEUE del(QUEUE Q)
{
 if (Q.front > Q.rear) 
   printf("Queue empty\n");
 else
  printf("The element deleted is %d\n",Q.queue[Q.front++]);
  return Q;
}

void disp(QUEUE Q)
{
   int i;
 if (Q.front > Q.rear){
   printf("Queue empty\n");
   return; }
       for (i = Q.front; i <= Q.rear; i++)
       printf("%d\t",Q.queue[i]);
       printf("\n");
}

void main()
{
  QUEUE Q;
  Q.queue=(int*)malloc(max_size*sizeof(int));
  Q.front = -1;
  Q.rear = -1;
  int val,ele, choice;
    printf("1.circular queue\n2.priority queue\n");
    printf("Enter your choice\n");
    scanf("%d", &choice);
    switch (choice){
      case 1:
      printf("1: Insert\n2: Delete\n3.Display\n4: Exit\n");
     for (;;)
     {
    printf("Enter your choice\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the element\n");
      scanf("%d", &val);
      Q=insert(Q, val);
      break;
    case 2:
      Q=delete (Q);
      break;
    case 3:
      display(Q);
      break;
    default:
      exit(0);
    }
  }
  case 2:Q.front=0;
  printf("1: Insert \n2: Delete Rear\n3: Display\n0: Exit\n");
  for(;;){ 
    printf("Enter your choice\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the element\n");
      scanf("%d", &ele);
      Q=ins(Q, ele);
      break;
    case 2:
      Q=del(Q);
      break;
    case 3:
      disp(Q);
      break;
    default:
      exit(0);}
    }
  }
  }
