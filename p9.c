//Develop a menu driven program to convert infix expression to postfix expression using stack (Test for nested parenthesized expressions)
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int stackprec(char symbol){
switch(symbol){
case '+' : 
case '-' : return 2;
case '*' :
case '/' :
case '%' : return 4;
case '^' :
case '$' : return 5;
case '(' : return 0;
case '#' : return -1;
default : return 8;
}
}

int inprec(char symbol){
switch(symbol){
case '+' : 
case '-' : return 1;
case '*' :
case '/' :
case '%' : return 3;
case '^' :
case '$' : return 6;
case '(' : return 9;
case ')' : return 0;
default : return 7;
}
}

void infixtopostfix(char infix[], char postfix[]){
char S[30]; 
int i=0; 
int j=0; 
int top=-1; 
S[++top] = '#';
char symbol;
for(i=0;i<strlen(infix);i++){
symbol = infix[i];
while(stackprec(S[top])>inprec(symbol))
postfix[j++]=S[top--];
if(stackprec(S[top])!=inprec(symbol))
S[++top] = symbol;
else
top--;
}
while(S[top]!='#'){
postfix[j]=S[top--];
j++;
}
postfix[j]='\0';
}
void main(){
char infix[30]; 
char postfix[30];
int choice;
printf("1.Convert to Postfix\n0.Exit\n");
for(;;){
printf("Enter Your Choice: ");
scanf("%d",&choice);
switch (choice){
case 1 : printf("Enter the Infix Expression : ");
scanf("%s",infix);
 infixtopostfix(infix,postfix);
printf("The Postfix Expression is : ");
printf("%s\n",postfix);
break;
case 0 : printf("!! THANK YOU !!\n");
exit(0);
default: printf("Invalid Choice\n");
}
}
}
