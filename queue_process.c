#include<stdio.h>

struct queue{
	int q[10],front,rear;
}p,t;
void insert(int,struct queue*);
int delete(struct queue*);
void main()
{
    int n,i,ele1,ele2,rt=0,pr;
    p.front=0;p.rear=-1;
    t.front=0;t.rear=-1;
	printf("Enter the number of processes:");
	scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    printf("\nEnter the id. number of process:");
	scanf("%d",&ele1);
	insert(ele1,&p);	
	
	printf("\nEnter the burst time of process:");
	scanf("%d",&ele2);
	insert(ele2,&t);	
	}
	for(i=0;i<n;i++)
	{
	    pr=delete(&p);
	  	printf("\nThe process %d starts at %d sec(s)",pr,rt);
		rt+=delete(&t);
		printf("\nThe process %d ends at %d sec(s)",pr,rt);
	}
	
}
void insert(int ele,struct queue *k)
{
	if(k->rear== 9)
	{
		printf("\nQueue overflow");
		return ;
	}
	else
	k->q[++k->rear]=ele;
}
int delete(struct queue *k)
{
	if(k->front > k->rear)
	{
		printf("\nQueue underflow");
		return -9999;
	}
	else
	return k->q[k->front++];
}
