//Develop a menu driven program to evaluate postfix and prefix expressions using stack.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void prefixevaluate(char prefix[])
{
int i,op1,op2,res;
strrev(prefix);
int Stack[10]; 
int top=-1;
char ch;
for(i=0;i<strlen(prefix);i++)
{
ch = prefix[i];
if(isdigit(ch))
{
Stack[++top]=ch-'0'; 
}
else
{
if(top<1)
printf("Not enough operands\n");
else
{
op1=Stack[top--]; 
op2=Stack[top--]; 
switch (ch)
{
case '+' : res = op1 + op2;
break;
case '-' : res = op1 - op2;
break;
case '/' : res = op1 / op2;
break;
case '*' : res = op1 * op2;
break;
case '%' : res = op1 % op2;
break;
default: printf("Invalid Operator\n");
}
Stack[++top] = res; 
}
}
}
printf("Final Result = %d\n",Stack[top]);
}

void postfixevaluate(char postfix[])
{
int i,op1,op2,res;
int Stack[10]; 
int top=-1; 
char ch;
for(i=0;i<strlen(postfix);i++)
{
ch = postfix[i];
if(isdigit(ch))
{
Stack[++top]=ch-'0'; 
}
else
{
if(top<1)
printf("Not enough operands\n");
else
{
op2=Stack[top--]; 
op1=Stack[top--];
switch (ch)

{
case '+' : res = op1 + op2;
break;
case '-' : res = op1 - op2;
break;
case '/' : res = op1 / op2;
break;
case '*' : res = op1 * op2;
break;
case '%' : res = op1 % op2;
break;
default: printf("Invalid Operator\n");
}
Stack[++top] = res; //Pushing Result into Stack
}
}
}
printf("Final Result = %d\n",Stack[top]);
}

void main()
{
char prefix[30]; 
char postfix[30]; 
int choice;
printf("Menu\n1.evaluate prefix\n2.Evaluate Postfix\n0.Exit\n");
for(;;)
{
printf("Enter Your Choice: ");
scanf("%d",&choice);
switch (choice)
{
case 1 : printf("Enter the prefix Expression : ");
scanf("%s",prefix);
prefixevaluate(prefix);
break;
case 2:printf("Enter the postfix Expression : ");
scanf("%s",postfix);
postfixevaluate(postfix);
break;
case 0 : printf("!! THANK YOU !!\n");
exit(0);
default: printf("Invalid Choice\n");
}
}
}
