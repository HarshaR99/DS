#include<stdio.h>
#include<stdlib.h>
struct list{
int data; struct list *next;
};
typedef struct list* node;

node create(){
node p = (node)malloc(sizeof(struct list));
if(p!=NULL)
return p;
else{
printf("\nNo memory allocated");
exit(0);
}}

node insert(int ele,node head){
node p=create();
p->data=ele;
p->next=head;
head=p;
return head;
}

node delete(node head){
node p=head,prev=NULL;int ele;
if(p==NULL){
printf("\nQueue underflow");
return head;
}
else if(p->next==NULL){
ele=p->data;
free(p);
head=NULL;
printf("\nThe element deleted is %d",ele);
return head;
}
while(p->next!=NULL){
prev=p;
p=p->next;
}
ele=p->data;
free(p);
prev->next=NULL;
printf("\nThe element deleted is %d",ele);
return head;
}
void display(node head){
node p=head;
if(p==NULL){
printf("\nQueue is empty");
return;
}
while(p!=NULL){
printf("\n%d",p->data);
p=p->next;
}
}

int main(){
int ch,ele;node head=NULL;
printf("Enter:\n1 to insert\n2 to delete\n3 to display\nany other key to exit");
do{
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch){
case 1:
printf("\nEnter element you want to insert:");
scanf("%d",&ele);
head = insert(ele,head);
break;
case 2:
head=delete(head);
break;
case 3:
display(head);break;
default:printf("\nExit");
exit(0);
}
}while(ch>0&&ch<4);
return 0;
}
