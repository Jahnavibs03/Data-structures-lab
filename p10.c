//Develop a menu driven program to convert infix expression to prefix expression using stack (Test for nested parenthesized expressions)
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int stackprec(char symbol)
{
switch(symbol)
{
case '+' : 
case '-' : return 1;
case '*' :
case '/' :
case '%' : return 3;
case '^' :
case '$' : return 6;
case ')' : return 0;
case '#' : return -1;
default : return 8;
}
}

int inprec(char symbol)
{
switch(symbol)
{
case '+' : 
case '-' : return 2;
case '*' :
case '/' :
case '%' : return 4;
case '^' :
case '$' : return 5;
case '(' : return 0;
case ')' : return 9;
default : return 7;
}
}

void infixtoprefix(char infix[], char prefix[])
{
char S[30]; 
int i=0;
int j=0;
int top=-1; 
S[++top] = '#';
char symbol;
char temp;
for(i=0;i<strlen(infix)/2;i++){
    temp=infix[i];
    infix[i]=infix[strlen(infix)-i-1];
    infix[strlen(infix)-i-1]=temp;
}
for(i=0;i<strlen(infix);i++)
{
symbol = infix[i];
while(stackprec(S[top])>inprec(symbol))
{
prefix[j++]=S[top--];
}
if(stackprec(S[top])!=inprec(symbol))
{
S[++top] = symbol;
}
else
{
top--;
}
}
while(S[top]!='#')
{
prefix[j]=S[top--];
j++;
}
prefix[j]='\0';
for(i=0;i<strlen(prefix)/2;i++){
    temp=prefix[i];
    prefix[i]=prefix[strlen(prefix)-i-1];
    prefix[strlen(prefix)-i-1]=temp;
}
}
void main()
{
char infix[30]; 
char prefix[30];
int choice;
printf("1.Convert to Prefix\n0.Exit\n");
for(;;)
{
printf("Enter Your Choice: ");
scanf("%d",&choice);
switch (choice)
{
case 1 : printf("Enter the Infix Expression : ");
scanf("%s",infix);
printf("The Prefix Expression is : ");
infixtoprefix(infix,prefix);
printf("%s\n",prefix);
break;
case 0: printf("!! THANK YOU !!\n");
exit(0);
default: printf("Invalid Choice\n");
}
}
}
