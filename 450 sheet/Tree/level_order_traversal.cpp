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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelorder;
        if(root==NULL)
            return levelorder;

        queue<TreeNode*> q1;
        q1.push(root);

        while(q1.empty()!=1)
        {
            vector<int> temp;
            int n=q1.size();

            for(int i=0;i<n;i++)   // for(int i=0;i<q1.size();i++)  wrong as q1.size() changes due to pop()                                               q1.pop()
            {
                temp.push_back(q1.front()->val);

                if(q1.front()->left!=NULL)
                    q1.push(q1.front()->left);
                if(q1.front()->right!=NULL)
                    q1.push(q1.front()->right);

                q1.pop();
            }

            levelorder.push_back(temp);
        }
        return levelorder;
    }
};
