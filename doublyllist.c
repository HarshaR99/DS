#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node *NODE;
NODE getnode(){
    NODE p;
    p = (NODE)malloc(sizeof(struct node));
    if(p != NULL)
        return p;
    else{
    	printf("Memory could not be allocated");
        exit(0);
    }
}
NODE insert_beg(NODE head, int ele){
    NODE p;
    if(head == NULL){
        p = getnode();
        p->data = ele;
        p->next = head;
        return p;
    }
    p = getnode();
    p->data = ele;
    head->prev =p;
    p->next = head;
    return p;
}

NODE insert_left(NODE head,int key){

if(head==NULL)
return head;
int ele;
printf("\nEnter value to be inserted:");
scanf("%d",&ele);
NODE trav=head;
while(trav!=NULL&&trav->data!=key)
trav=trav->next;
if(trav->data!=key)
return head;
if(trav==head){
NODE p=getnode();
p->data=ele;
p->next=head;
p->prev=NULL;
head->prev=p;
head=p;
return head;
}
else{
NODE p=getnode();
p->data=ele;
trav->prev->next=p;
p->prev=trav->prev;
trav->prev=p;
p->next=trav;
return head;
}
}

void display(NODE head){
	NODE p;
	if(head == NULL){
		printf("List is empty\n");
		return;
	}
	p = head;
	while(p != NULL){
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
}
NODE delete(NODE head, int ele){
    if(head == NULL){
        printf("Empty!\n");
        return head;
    }
    NODE p = head;
    while(p->data != ele){
        if(p->next == NULL){
            printf("Not found!\n");
            return head;
        }
        p = p->next;
    }
    //Found now
    if((p->prev == NULL) && (p->next == NULL)){
        free(p);
        printf("Found and deleted!\n");
        return NULL;
    }
    if(p->prev == NULL){
        p->next->prev = NULL;
        head = p->next;
        free(p);
        printf("Found and deleted!\n");
        return head;
    }
    if(p->next == NULL){
        p->prev->next = NULL;
        free(p);
        printf("Found and deleted!\n");
        return head;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    printf("Found and deleted!\n");
    return head;
}
int main(){
    NODE head = NULL;
    int choice, ele, n, pos, value;
printf("1. Insert at the Front\n2. Search and delete specific element\n3. Display\n4. insert left of element\n5 to exit\n");
	do{
		printf("Enter option : ");
		scanf("%d", &choice);
		switch(choice){
			case 1: printf("Enter element to insert : ");
                    scanf("%d", &ele);
                    head = insert_beg(head, ele);
                    break;
            case 2: printf("Enter element to Delete : ");
                    scanf("%d", &ele);
                    head = delete(head, ele);
                    break;
            case 3: display(head);
                    break;
            case 4: printf("Enter element :");
		scanf("%d",&ele);			
		head=insert_left(head,ele);
		break;
		case 5: return 0;
		}
	}while(choice != 5);
	return 0;
}
