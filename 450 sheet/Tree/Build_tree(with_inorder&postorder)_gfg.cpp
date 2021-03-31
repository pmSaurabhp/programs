
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        TreeNode *root=NULL;

        if(inorder.size()==0)  { return root; }

        root=new TreeNode(postorder[postorder.size()-1]);
        build_fun(inorder,postorder,root);
        return root;
    }

    int linear_search(vector<int> arr,int key)
    { for(int i=0;i<arr.size();i++)
     {
       if(arr[i]==key)
         {
           return i;
         }
      }
    return 0;
    }
    void build_fun(vector<int> inorder,vector<int> postorder,TreeNode *root)
{
    int n,i;
    vector<int> t1,t2,t3,t4;


    n=postorder[postorder.size()-1];
    i=linear_search(inorder,n);

    for(int j=0;j<i;j++)
    {  t1.push_back(inorder[j]);  }
    for(int j=i+1;j<inorder.size();j++)
    {  t2.push_back(inorder[j]);  }
    for(int j=0;j<t1.size();j++)
    {  t3.push_back(postorder[j]);  }
    for(int j=t1.size();j<postorder.size()-1;j++)
    {  t4.push_back(postorder[j]);  }

     if(t3.size()>=1)
     { TreeNode *a1=new TreeNode(t3[t3.size()-1]);
      root->left=a1;
       build_fun(t1,t3,a1);
     }
     if(t4.size()>=1)
     { TreeNode *a2=new TreeNode(t4[t4.size()-1]);
         root->right=a2;
         build_fun(t2,t4,a2);
     }

}

};

