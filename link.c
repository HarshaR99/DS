#include<stdio.h>
#include<stdlib.h>
struct list{
int data;
struct list *next;
};
typedef struct list* node;
node create(){
node p =(node)malloc(sizeof(struct list));
if(p==NULL){
printf("\no memory allocated,");
return NULL;
}return p;
}
node insert_front(int ele,node head){
node p = create();
p->data=ele;
p->next=head;
head=p;
return head;
}
void insert_end(int ele,node head)
{
node p =create(),q=head;
p->data=ele;
while(q->next!=NULL){
q=q->next;}
q->next=p;
p->next=NULL;
}

node insert_pos(int ele,int pos,node head){
node p=create(),curr=head,prev=NULL;
int count=1;
p->data=ele;
p->next=NULL;
if(head==NULL){
if(pos==1)
return p;
else{
printf("\nInvalid position");
return head;
}}
if(pos==1){
p->next=head;
head=p;
return head;
}
else{
while(curr!=NULL&&count!=pos){
prev=curr;
curr=curr->next;count++;
}
if(count==pos){
prev->next=p;
p->next=curr;
return head;
}
else{
printf("\nInvalid postion");}
}
}
void display(node head){
node p=head;
if(head==NULL)
printf("\nList is empty");
else
printf("\nThe elements of list are:");
while(p!=NULL){
printf("\n%d",p->data);
p=p->next;
} 
}

node delete_front(node head)
{
int ele;node p=head;
if(head==NULL){
printf("\nList is empty.");
return head;
}
else{
ele=head->data;
head=p->next;
free(p);
printf("\nThe element deleted is %d",ele);
return head;
}
}
node delete_rear(node head){
node p=head,prev=NULL;int ele;
if(head==NULL){
printf("\nList is empty.");
return head;
}
while(p->next!=NULL){
prev=p;
p=p->next;
}
ele=p->data;
printf("\nThe deleted element is %d",ele);
free(p);
prev->next=NULL;
return head;
}

int main(){
node head=NULL;
int ch,ele,pos;
printf("Enter 1 to insert_front,2 to insert_rear,3 to insert at a position,\n4 to delete from front,5 to delete from rear,6 to display,any other to exit:");
do{
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch){
case 1:printf("\nEnter element to insert: ");
scanf("%d",&ele);
head=insert_front(ele,head);
break;
case 2:printf("\nEnter the element to be inserted: ");
scanf("%d",&ele);insert_end(ele,head);
break;
case 3:printf("\nThe element to be inserted: ");
scanf("%d",&ele);
printf("\nEnter the postion : ");
scanf("%d",&pos);
head=insert_pos(ele,pos,head);
break;
case 4:
head=delete_front(head);break;
case 5:
head=delete_rear(head);break;
case 6:display(head);
break;
default:
printf("\nEnd of program");
}
}while(ch>0&&ch<7);
return 0;
}




