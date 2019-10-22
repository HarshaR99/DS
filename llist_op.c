#include<stdio.h>
#include<stdlib.h>
struct list{
int data;struct list* next;
};
typedef struct list* node;

node create(){
node p = (node)malloc(sizeof(struct list));
if(p!=NULL)
return p;
else exit(0); }

node insert_rear(node head){
node newn=create();int val;
printf("\nEnter value to be insterted:");
scanf("%d",&val);
newn->data=val;
newn->next=NULL;
if(head==NULL){
return newn;}
else{
node trav=head;
while(trav->next!=NULL)
trav=trav->next;
trav->next=newn;
return head;
}
}

node sortll(node head){
if(head==NULL)
return head;
int temp;node curr=head,trav;
while(curr->next!=NULL){
trav=curr->next;
while(trav!=NULL){
if(curr->data>trav->data){
temp=curr->data;
curr->data=trav->data;
trav->data=temp;
} trav=trav->next;
}curr=curr->next;
}
return head;
}

node reverse_ll(node head){
if(head==NULL)
return head;
node prev=NULL,curr=head,nextn=NULL;
while(curr!=NULL){
nextn=curr->next;
curr->next=prev;
prev=curr;
curr=nextn;
}
head=prev;
return head;
}

void display(node head){
node trav=head;
while(trav!=NULL){
printf("\n%d",trav->data);
trav=trav->next;
}
}
node concatnate(node head1,node head2){
if(head1==NULL)
return head2;
if(head2==NULL){
return head1;}
else{
node trav=head1;
while(trav->next!=NULL){
trav=trav->next;
}
trav->next=head2;

}return head1;
}
void deleteall(node head){
while(head!=NULL){
node del=head;
head=head->next;
free(del);
}
}


int main(){
int ch;node head = NULL, head1=NULL;
printf("Enter:\n1 to insert\n2 to sort\n3 to reverse\n4 to display\n5 to concatnate");
do{
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch){
case 1:head = insert_rear(head);
	head1=insert_rear(head1);break;
case 2:head= sortll(head);break;
case 3:head = reverse_ll(head);break;
case 4:display(head);break;
case 5:head=concatnate(head,head1);break;
default:deleteall(head);exit(0);
}
}while(ch>0&&ch<7);
return 0;
}

