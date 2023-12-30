
//a)	Define a structure called Student with the members: Name, Reg_no, marks in 3 tests and average_ marks. Develop a menu driven program to perform the following by writing separate function for each operation: a) read information of N students b) display student’s information c) to calculate the average of best two test marks of each student. Note: Allocate memory dynamically and illustrate the use of pointer to an array of structure. 
//b)	Define a structure called Time containing 3 integer members (Hour, Minute, Second). Develop a menu driven program to perform the following by writing separate function for each operation. a) Read (T) :To read time b) Display (T):To display time c) update(T):To Update time d) Add (T1, T2) : Add two time variables. Update function increments the time by one second and returns the new time (if the increment results in 60 seconds, then the second member is set to zero and minute member is incremented by one. If the result is 60 minutes, the minute member is set to zero and the hour member is incremented by one. Finally, when the hour becomes 24, Time should be reset to zero. While adding two time variables, normalize the resultant time value as in the case of update function. Note: Illustrate the use of pointer to pass time variable to different functions
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct student{
char name[50];
int rn;
float m[3];
float avgm;
}STUDENT;
int n;

STUDENT *read(STUDENT *s){
    printf("enter number of students required: ");
    scanf("%d",&n);
    s=(STUDENT*)malloc(n*sizeof(STUDENT));
    for(int i=0;i<n;i++){
        printf("enter name of student-%d: ",i+1);
        scanf("%s",s[i].name);
        printf("enter roll number of student-%d: ",i+1);
        scanf("%d",&s[i].rn);
        for(int j=0;j<3;j++){
            printf("enter test %d marks of student -%d: ",(j+1),(i+1));
            scanf("%f",&s[i].m[j]);
        }
    }
    return s;
}

void display(STUDENT *s){
    printf("NAME\tROLL NO\tTEST-1\tTEST-2\tTEST-3\t\n");
    for(int i=0;i<n;i++){
    printf("%s\t%d\t%f\t%f\t%f\t\n",s[i].name,s[i].rn,s[i].m[0],s[i].m[1],s[i].m[2]);
    }
}

STUDENT *calcavg(STUDENT *s){
    printf("NAME\tAVERAGE MARKS\t\n");
    for(int i=0;i<n;i++){
        if(s[i].m[0]<=s[i].m[1]&&s[i].m[0]<=s[i].m[2])
        s[i].avgm=(s[i].m[2]+s[i].m[1])/2;
        if(s[i].m[1]<=s[i].m[0]&&s[i].m[1]<=s[i].m[2])
        s[i].avgm=(s[i].m[2]+s[i].m[0])/2;
        if(s[i].m[2]<=s[i].m[1]&&s[i].m[2]<=s[i].m[1])
        s[i].avgm=(s[i].m[1]+s[i].m[0])/2;
        printf("%s\t%f\t\n",s[i].name,s[i].avgm);
    }
    return s;
}

void main(){
    STUDENT *s;
    int choice;
    printf("1.read the student's information\n2.display\ncalculate average\n0.exit\n");
    do{
        printf("enter choice: ");scanf("%d",&choice);
        switch(choice){ 
        case 1:s=read(s);break;
        case 2:display(s);break;
        case 3:s=calcavg(s);break;
        case 0:printf("-----------------------------------------------------THANKYOU---------------------------------------------------------\n");break;
        default:printf("wrong choice\n");break;
        }
    }while(choice!=0);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct time{
    int h,m,s;
}TIME;

TIME *read(TIME *p);
TIME *update(TIME *p);
TIME *correct(TIME *p);
void display(TIME *p);
TIME *add();

TIME *read(TIME *p){
    printf("enter time in hour:minute:second format:  " );
    scanf("%d %d %d",&p->h,&p->m,&p->s);
   p=correct(p);
    return p;
}

TIME *update(TIME *p){
    p->s=p->s+1;
   p=correct(p);
    return p;
}

TIME *correct(TIME *p){
     if(p->s>=60){
        p->m=p->m+p->s/60;
        p->s%=60;
    }
    if(p->m>=60){
        p->h=p->h+p->m/60;
        p->m%=60;
    }
     if(p->h>=24)
    {p->h%=24;}
    return p;
   }

void display(TIME *p){
    printf("TIME :\n%d:%d:%d\n",p->h,p->m,p->s);
}

TIME *add(TIME *a,TIME *q){
    TIME *r;    
    r->h=a->h+q->h;
    r->m=a->m+q->m;
    r->s=a->s+q->s;
    r=correct(r);
    return r;
}

void main(){
    TIME *p,sr,*a,sp,*q,sq;
    p=&sr;
    a=&sp;
    q=&sq;
    int choice;
    printf("1.read time\n2.display time\n3.update time\n4.add two time\n0.exit\n");
    do{
        printf("enter choice: ");scanf("%d",&choice);
        switch(choice){
            case 1:p=read(p);break;
            case 2:display(p);break;
            case 3:p=update(p);break;
            case 4:q=read(q);a=read(a);p=add(a,q);break;
            case 0:printf("---------THANKYOU--------\n");break;
            default:printf("wrong choice\n");break;

        }
    }while(choice!=0);
}
