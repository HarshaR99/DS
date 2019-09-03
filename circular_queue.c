#include<stdio.h>

struct queue{
	int q[10],front,rear;
}q1;
void insert(int,struct queue* );
int delete(struct queue*);
void display(struct queue);
int main()
{
q1.front=-1;q1.rear=-1;
int ch,ele;
printf("Enter 1 to insert,2 to delete,3 to display or any other value to exit");
do{
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
        {
        case 1:
            printf("\nEnter the element to be inserted: ");
            scanf("%d",&ele);
            insert(ele,&q1);
            break;
        case 2:
            ele = delete(&q1);
            if(ele== -9999)
               {
                printf("\nQueue Underflow");
               }
            else
            printf("\nThe deleted element is %d ",ele);
            break;
        case 3:
            display(q1);
            break;
        default:
            printf("\nThe program has ended ");
        }
}while(ch== 1||ch== 2||ch== 3);

return 0;
}

void insert(int ele,struct queue *k)
{
if(k->front == (k->rear +1)||(k->front==0 && k->  rear ==9))
{
printf("\nQueue Overflow");
return;
}
if(k->front==-1)
k->front=0;

k->rear=(k->rear +1)%10;
k->q[k->rear]=ele;
}

int delete(struct queue *k)
{
int item;
if(k->front==-1)
{
printf("Queue is Empty");
return -9999;
}
else
item=k->q[k->front];

if(k->rear==k->front)
{
k->front=-1;
k->rear=-1;
}
else
k->front=(k->front+1)%10;
return item;
}
void display(struct queue k)
{
int i;
printf("\nThe elements in queue are:");
if(k.front==-1)
{
printf("\nQueue is Empty");
return;
}
for(i=k.front;i!=k.rear;i=(i+1)%10)
{printf("\n%d",k.q[i]);
}
printf("\n%d",k.q[i]);
}
