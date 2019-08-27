#include<stdio.h>
#include<string.h>
#include<math.h>
struct stack{
int a[10];
int top;
};
void push(int ,struct stack*);
int pop(struct stack*);
int isop(char);
int evaluate(int,int,char);

int main()
{
struct stack s;char exp[10];int l,i,op1,op2,v=0;
s.top=-1;
printf("Enter the postfix epression: ");
gets(exp);
l=strlen(exp);
for(i=0;i<l;i++)
{
if(!isop(exp[i]))
push(exp[i]-'0',&s);

else
{
op2=pop(&s);
op1=pop(&s);
v=evaluate(op1,op2,exp[i]);
push(v,&s);
}


}

printf("\nThe final value is: %d",pop(&s));
return 0;
}
void push(int e,struct stack *k)
{
   if(k->top==9)
   printf("\nStack Overflow");
   
   else
    k->a[++k->top]=e;
}
int pop(struct stack *k)
{
if(k->top==-1){
printf("\nStack Underflow");
return -9999;
}
else
return k->a[k->top--];

}

int isop(char e)
{
if(e=='+'||e=='-'||e=='*'||e=='/'||e=='^')
return 1;
else
return 0;
}
int evaluate(int a,int b,char c)
{

switch(c)
{
case '+':
return a+b;
break;
case '-':
return a-b;
break;
case '*':
return a*b;
break;
case '/':
return (int)a/b;
break;
case '^':
return pow(a,b);
break;
default:
printf("\nError");
return -9999;
}
}
