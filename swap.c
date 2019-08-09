#include <stdio.h>
void swap(int*,int*);
int main()
{
	int a,b;
	printf("Enter the two numbers to be swapped");
	printf("\nEnter the first number : ");
	scanf("%d",&a);
	printf("\nEnter the second number : ");
	scanf("%d",&b);
	swap(&a,&b);
	printf("\nAfter swapping the values of the first and second numbers have become %d and %d.",a,b);
	return 0;
}
void swap(int *p,int*q)
{
	*p = *p + *q; 
	*q = *p - *q; 
	*p = *p - *q;
}