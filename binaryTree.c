#include<stdio.h>
#include<stdlib.h>
struct list{
int data;
struct list* lchild;
struct list* rchild;
};
typedef struct list* node;

node create(int item){
node p = malloc(sizeof(struct list));
p->data=item;
p->lchild=NULL;
p->rchild=NULL;
return p;
}

node insert(node root,int item){
if(root==NULL)
return create(item);

else if(item<root->data)
root->lchild=insert(root->lchild,item);

else if(item>root->data)
root->rchild=insert(root->rchild,item);
}

void inorder(node root){
if(root==NULL)
return;
inorder(root->lchild);
printf("\n%d",root->data);
inorder(root->rchild);
}

void preorder(node root){
if(root==NULL)
return;
printf("\n%d",root->data);
preorder(root->lchild);
preorder(root->rchild);
}

void Postorder(node root) 
{ 
     if (root == NULL) 
        return; 
     Postorder(root->lchild); 
     Postorder(root->rchild); 
     printf("%d ",root->data ); 
} 

int main(){
node root =NULL;
printf("1.insert element\n2.inorder\n3.preorder\n4.postorder\n5.Exit");
int choice,ele;
do{
printf("\nEnter choice:");
scanf("%d",&choice);
switch(choice){
case 1:printf("\nEnter element:");
scanf("%d",&ele);
root=insert(root,ele);
break;
case 2:inorder(root);break;
case 3:preorder(root);break;
case 4:Postorder(root);break;
default:exit(0);

}
}while(choice!=5);
return 0;
}






