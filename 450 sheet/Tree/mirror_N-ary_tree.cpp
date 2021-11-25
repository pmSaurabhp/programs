#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
struct Node
{

    int val;
    std::vector<Node*> children;
    Node(int a)
    {
        val=a;

    }


};
Node* build_tree(std::vector<int> &arr)  // root=&a;
    { Node* root=NULL;


        std::queue<Node*> q1;


        for(int i=0;i<arr.size();i=i+2)
        { Node *temp=NULL;
          int val1=arr[i];
          int val2=arr[i+1];

            if(root==NULL)
            {
                root=new Node(val1);
                q1.push(root);
            }

            if(val1==q1.front()->val)
            {  temp=new Node(val2);
                q1.front()->children.push_back(temp);
                q1.push(temp);
            }
            else
            {
                q1.pop();

                while(q1.front()->val!=val1)
                { q1.pop(); }

                temp=new Node(val2);
                q1.front()->children.push_back(temp);
                q1.push(temp);
            }

        }

        return root;
    }
void levelOrder(Node *root,std::vector<std::vector<int>> &levelorder) {

        if(root==NULL)
            return ;

        std::queue<Node*> q1;
        q1.push(root);

        while(q1.empty()!=1)
        {
            std::vector<int> temp;
            int n=q1.size();

            for(int i=0;i<n;i++)
            {
                temp.push_back(q1.front()->val);

                for(int j=0;j<q1.front()->children.size();j++)
                {
                    q1.push(q1.front()->children[j]);
                }
                q1.pop();
            }

            levelorder.push_back(temp);
        }
    }
int main() {

	int t;
	std::cin>>t;
	while(t--)
	{int n,e;
	std::vector<std::vector<int>> c,d;
	    std::cin>>n>>e;
	Node *a=NULL,*b=NULL;
  std::vector<int> arr1,arr2;
  int ne=n*2-2;
  int val;
  for(int i=0;i<ne;i++)
  {  std::cin>>val;
      arr1.push_back(val);
  }
    for(int i=0;i<ne;i++)
  {  std::cin>>val;
      arr2.push_back(val);
  }

	a=build_tree(arr1);
	b=build_tree(arr2);


	levelOrder(a,c);
	levelOrder(b,d);
    free(a);
    free(b);

	int k=1;

	    for(int i=0;i<c.size();i++)
     {
	    reverse(c[i].begin(),c[i].end());
	    for(int j=0;j<d[i].size();j++)
	    {

	        if(c[i][j]!=d[i][j])
	        {k=0;
	        break;
	        }
	    }
	 }


	 std::cout<<k<<"\n";

	}
	return 1;
}
