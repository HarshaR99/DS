#include<stdio.h>
struct student
{
	int id,age,marks;
}s;

void main()
{
printf("Enter details of student " );
    printf("\nID number : ");
    scanf("%d",&s.id);
    printf("\nAge : ");
    scanf("%d",&s.age);
    printf("\nMarks : ");
    scanf("%d",&s.marks);
    if (s.age>20 && s.marks>=0 && s.marks <= 100 )
    {
    	if (s.marks>=65)
    	{
    		printf("\nStudent is eligible.");
    	}
    	else
    		{printf("\nNot Eligible");
           }
    }
    else {
    	printf("\nData not valid.");
    }
}