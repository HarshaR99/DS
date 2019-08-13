/*
Name : Harsha R
USN : 1BM18CS034
Pgm name : stackh.c
Date : 13/8/19
*/
#include<stdio.h>
void push(int , int*,int *);
int pop(int *,int *);
void display(int* ,int *);
int main()
{
    int stack[100],top = -1,c,ele,p;
    do
    {
        printf("\nEnter 1 for push,2 for pop,3 for display any other for exit: ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("\nEnter the element to be pushed: ");
            scanf("%d",&ele);
            push(ele,stack,&top);
            break;
        case 2:
            p = pop(stack,&top);
            if(p== -9999)
               {
                printf("\nStack Underflow");
               }
            else
            printf("\nThe popped element is %d ",p);
            break;
        case 3:
            display(stack,&top);
            break;
        default:
            printf("\nThe program has ended ");
        }
    }while(c ==1 || c== 2 || c == 3);
    return 0;
}
void push(int ele,int s[100], int *t )
{
    if(*t == 99)
        printf("\nStack Overflow");
    else
    s[++(*t)] = ele;
}
int pop(int s[100],int *t)
{
    if(*t == -1)
   {
       return -9999;
   }
    else
      {
        return s[(*t)--];
      }
}
void display(int s[100],int *t)
{
    int i;
    if(*t == -1)
    {
        printf("\nNo elements present.");
    }
    else
    {
        for(i = *t;i >=0 ; i--)
        {
            printf("\n%d",s[i]);
        }
    }
}


