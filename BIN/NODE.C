#include<conio.h>
#include<stdio.h>
struct node
{ int data;
  struct node* left,*right;
};
void fun(struct node *a);
void main()
{ struct node *root,*newnode;
  clrscr();
   root->data=5;
   printf("%d  %d      %d     %d",root->left,root->data,root->right,*root);
   root=7;
   printf("\n%d %d  %d %d",root->left,root->data,root->right,*root);
   newnode=root;
   printf("\n%d %d  %d %d",newnode->left,newnode->data,newnode->right,*newnode);
   fun(root);
   getch();
}
void fun(struct node *a)
{ printf("\n%d %d  %d %d",a->left,a->data,a->right,*a);
}
    // root=&root->data