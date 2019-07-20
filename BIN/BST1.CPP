#include<conio.h>
#include<stdio.h>

struct bst
{ int data;
  struct bst *left;
  struct bst *right;
};
struct bst* insert(struct bst* root,int data);
void search(struct bst* root,int data);

void main()
{
struct bst* root=NULL;
 clrscr();
  root->left=root->right=NULL;

 printf("%d %d %d %d",root->left,root->data,root->right,*root);
 root=insert(root,30);

 root=insert(root,20);
 printf("\n%d %d %d %d",root->left,root->data,root->right,*root);
 root=insert(root,40);
 root=insert(root,10);

 search(root,50);
 getch();
}

struct bst* insert(struct bst* root,int data)
{ struct bst *newnode;
newnode->data=data;

printf("\n%d %d %d %d",root->left,root->data,root->right,*root);
  if(root==NULL)
  { root->data=newnode->data; }
  else
  { if(root->data>newnode->data)
     { root->left=insert(root->left,newnode->data);
     }
     else
     {root->right=insert(root->right,newnode->data);
     }
  }

return root;
}
void search(struct bst *root,int data)
{ struct bst* newnode;
  newnode->data=data;
 if(root==newnode)
   {printf(" found");
   }
   else
   {if(root>newnode)
     { search(root->left,newnode->data);}
    else
     { search(root->right,newnode->data); }
    }
}