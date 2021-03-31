// run in leet code
// https://leetcode.com/explore/learn/card/data-structure-tree/133/conclusion/942/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        TreeNode *root=NULL;

        if(inorder.size()==0)  { return root; }
        int pre_ptr=0;
        root=build_fun(preorder,inorder,0,inorder.size()-1,&pre_ptr);
        return root;
    }

    int linear_search(vector<int> &inorder,int instart,int inend,int key)
    { for(int i=instart;i<=inend;i++)
     {
       if(inorder[i]==key)
         {
           return i;
         }
      }
    return 0;
    }
    TreeNode* build_fun(vector<int> &preorder,vector<int> &inorder,int instart,int inend,int *pre_ptr)
{
    int i;

        if (instart > inend)
           return NULL;

        TreeNode *root=new TreeNode(preorder[*pre_ptr]);
        (*pre_ptr)++;

        if(instart==inend)  { return root; }

        i=linear_search(inorder,instart,inend,root->val);

        root->left=build_fun(preorder,inorder,instart,i-1,pre_ptr);
        root->right=build_fun(preorder,inorder,i+1,inend,pre_ptr);

     return root;
}

};
