#include<stdio.h>
#include<string.h>
struct stack{
char in[20];
int top;
};
void push(char c,struct stack *k)
{if(k->top==19)
printf("Overflow");
else
k->in[++k->top]=c;
}
void pop(struct stack *k)
{
if(k->top==-1)
printf("Underflow");
else
{ if(k->in[k->top]!= '(')
    printf("%c",k->in[k->top--]);
  else
   k->top--;
}
}
int pre(char c)
{
switch(c)
{
case '+':
	return 1;
break;
case '-':
return 1;
break;
case '*':
	return 2;
	break;
case '/':
return 2;
break;
case '^':
return 3;
break;
default:
return 0;
break;
}
}
int isOP(char c)
{ if(c=='+'||c=='-'||c=='/'||c=='*'||c=='^')
   return 1;
  else
return 0;
}
int main()
{ struct stack s;int i;char exp[20];
s.top=-1;
printf("Enter the expression:");
gets(exp);
printf("\nThe postfix expression is :");
for(i=0;exp[i]!='\0';i++)
{ 
  if(!isOP(exp[i])&&exp[i]!='('&&exp[i]!=')')
  printf("%c",exp[i]);
 
 else if(exp[i]=='(')
  push(exp[i],&s);

 else if(isOP(exp[i]))
{
if(pre(exp[i]) > pre(s.in[s.top]))
  push(exp[i],&s);
 
  else
  { while(pre(exp[i]) <= pre(s.in[s.top]))
    {pop(&s);
	}
    push(exp[i],&s);
  }
}

 
   else if(exp[i]==')')
  { 
     do{
        pop(&s);
       } while(s.in[s.top] != '(');
   }
 
 else if(s.top==-1)
{ push(exp[i],&s);
}

else
printf("Error");
}
while(s.top!=-1)
{pop(&s);
}


return 0;
}

