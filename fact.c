/*
Program to calculate the factorial of a number
Harsha R
1BN18CS034
*/
#include<stdio.h>
int fact(int );
int main()
{
int n,f;
printf("Enter the number n:");
scanf("%d",&n);
f =fact(n);
printf("The factorial of %d is %d",n,f);
return 0;
}
int fact(int n)
{
if(n==1)
return 1;
else
return n*fact(n-1);
}
