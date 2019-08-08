#include <stdio.h>
#include <conio.h>
struct student {
	int id,age,marks;
};
int validate(struct student st);
int qualify(struct student st);
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
	if (qualify(s[i]))
	{
		printf("\nEligible for addmission");
	}
	else
	{
		printf("\nNot eligible for addmission");
	}
}
return 0;
}
 
 int validate(struct student st)
 {
 	if(st.age>20 && st.marks>=0 && st. marks< 100)
 		return 1;
 	else 
 		return 0;
 }
int qualify(struct student st)
{
	if(validate(st))
	{
		if(st.marks >= 65)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}