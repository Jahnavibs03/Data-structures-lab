//Develop a menu driven program to implement the following types of Queues by allocating memory dynamically. i) Circular Queue ii) Double ended Queue
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


QUEUE insert_rear(QUEUE Q, int item)
{
  if (Q.rear == max_size - 1){ 
    printf("Queue overflow\nreallocating memory\n");
    max_size++;
    Q.queue=(int*)realloc(Q.queue,max_size*sizeof(int));
  }
    Q.rear = Q.rear + 1;
    Q.queue[Q.rear] = item;
    if (Q.front == -1)
      Q.front = 0;
  return Q;
}

QUEUE insert_front(QUEUE Q, int item)
{
  if (Q.front == 0)
  {
    printf("cannot insert from front end\n");
   return Q;
  }  
  if (Q.front == -1){ 
    Q.front++;
    Q.rear = 0;}
  else
    Q.front--;
  Q.queue[Q.front] = item;
  return Q;
}

QUEUE delete_front(QUEUE Q)
{
  int item;
  if (Q.front == -1 || Q.front > Q.rear)
  {
    printf("Queue is empty\n");
    return Q;
  }
    item = Q.queue[Q.front];
    Q.front = Q.front + 1;
    printf("Deleted item is %d\n", item);
    return Q;
}

QUEUE delete_rear(QUEUE Q)
{
  int item;
  if (Q.rear == -1 || Q.front > Q.rear)
  {
    printf("Queue is empty\n");
    return Q;
  }
    item = Q.queue[Q.rear];
    Q.rear = Q.rear - 1;
    printf("Deleted item is %d\n", item);
    return Q;
}

void Ddisplay(QUEUE Q)
{
  int i;
  if (Q.rear != -1 && (Q.front > Q.rear))
    printf("\nQueue empty\n");
    else{ 
  printf("\nContents are :\n");
  for (i = Q.front; i <= Q.rear; i++)
    printf("%d\t", Q.queue[i]);
    printf("\n");
    }
}
void main()
{
  QUEUE Q;
  Q.queue=(int*)malloc(max_size*sizeof(int));
  Q.front = -1;
  Q.rear = -1;
  int val,ele, choice;
    printf("1.circular queue\n2.double ended queue\n");
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
  case 2:
  printf("1: Insert Front\n2: Insert Rear\n3: Delete Front\n4: Delete Rear\n5: Display\n0: Exit\n");
  for(;;){ 
    printf("Enter your choice\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the element\n");
      scanf("%d", &ele);
      Q=insert_front(Q, ele);
      break;
    case 2:
      printf("Enter the element\n");
      scanf("%d", &ele);
      Q=insert_rear(Q, ele);
      break;
    case 3:
      Q=delete_front(Q);
      break;
    case 4:
      Q=delete_rear(Q);
      break;
    case 5:
      Ddisplay(Q);
      break;
    default:
      exit(0);}
    }
  }
  }
