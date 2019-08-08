#include<stdio.h>
struct student
{
	int id,age,marks;
};
int main()
{
	int n,i;
struct student s[10];
printf("Enter number of students:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("\nEnter details of student %d:",i+1 );
    printf("\nID number : ");
    scanf("%d",&s[i].id);
    printf("\nAge : ");
    scanf("%d",&s[i].age);
    printf("\nMarks : ");
    scanf("%d",&s[i].marks);
    if (s[i].age>20 && s[i].marks>=0 && s[i].marks <= 100 )
    {
    	if (s[i].marks>=65)
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
return 0;
}
