//  Build tree with inorder and preorder

    int linear_search(int inorder[],int instart,int inend,int key)
    { for(int i=instart;i<=inend;i++)
     {
       if(inorder[i]==key)
         {
           return i;
         }
      }
    return 0;
    }
    Node* build_fun(int preorder[],int inorder[],int instart,int inend,int pol,int poh)
{  // cout<<instart<<" "<<inend<<" "<<pol<<" "<<poh<<"   ";
    int i;

        if (instart > inend || pol > poh)
           return NULL;

        Node *root=new Node(preorder[pol]);


        if(instart==inend)  { return root; }

        i=linear_search(inorder,instart,inend,root->data);
        int len = i-instart;  // length of left tree
        root->left=build_fun(preorder,inorder,instart,i-1,pol+1,pol + len);

        root->right=build_fun(preorder,inorder,i+1,inend,pol+1+len,poh);  // pol+1+i is wrong

     return root;
}
Node* buildTree(int in[],int pre[], int n)
{
     Node *root=NULL;

        if(n==0)  { return root; }
        int pre_ptr=0;
        root=build_fun(pre,in,0,n-1,0,n-1);
        return root;
}
