#include <stdio.h>

struct student {
	char name[20];
	int id;
	int marks[5];
	int grade[5];
	int credits[5];
};
int score(int);
float sgpa(struct student st,int);
int main()
{ 
 struct student s;int i;float gpa;int tcredit=0;

 printf("Enter name of student : ");
 gets(s.name);
 printf("\nEnter roll number of student : ");
 scanf("%d",&s.id);
for(i=1;i<=5;i++)
 {
 	printf("\nEnter mks of student in subject %d : ",i);
 	scanf("%d",&s.marks[i]);
 	printf("\nEnter number of credits of subject %d : ",i);
 	scanf("%d",&s.credits[i]);
 	tcredit += s.credits[i];
    s.grade[i] = score(s.marks[i]);
 }
 gpa = sgpa(s,tcredit);
 printf("\nThe SGPA scored by the student is %f",gpa);
 return 0;

}
int score(int mk)
{
	if (mk >= 90)
	return 10;
	else if (mk >= 75 && mk < 90)
	return 9;
	else if (mk >= 60 && mk < 75)
	return 8;
	else if (mk >= 50 && mk < 60)
	return 7;
	else if (mk >= 40 && mk < 50)
	return 6;
	else 
	return 0; 
}
float sgpa(struct student st, int c)
{ int i;float res=0;
	for(i=1;i<=5;i++)
	{
     res += st.grade[i]*st.credits[i];
	}
	res /= c;
	return res;
}
