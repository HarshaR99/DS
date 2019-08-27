#include<stdio.h>
int fib(int);
int main()
{
int n,f;
printf("Enter the number n:");
scanf("%d",&n);
f=fib(n);
printf("\nThe required number is %d",f);

return 0;
}
int fib(int n)
{
if(n==1||n==2)
return 1;
else
return fib(n-1)+fib(n-2);
}

