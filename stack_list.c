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

node push(int ele,node head){
node p=create();
p->data=ele;
p->next=head;
head=p;
return head;
}

node pop(node head){
int ele;node p=head;
if(p==NULL){
printf("\nStack underflow");
return p;}
ele=p->data;
head=p->next;
free(p);
printf("\nThe deleted element is %d",ele);
return head;
}

void display(node head){
node p=head;
if(p==NULL){
printf("\nStack is empty");
return;
}
printf("\nThe elements in stack are:");
while(p!=NULL){
printf("\n%d",p->data);
p=p->next;
}}

int main(){
int ch,ele;node head=NULL;
printf("Enter:\n1 to push\n2 to pop\n3 to display\nany other key to exit");
do{
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch){
case 1:
printf("\nEnter element you want to insert:");
scanf("%d",&ele);
head = push(ele,head);
break;
case 2:
head = pop(head);
break;
case 3:
display(head);break;
default:printf("\nExit");
exit(0);
}
}while(ch>0&&ch<4);
return 0;
}






















