#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Node{
public:
    int key;
   long long int sum;
    vector<Node*> child;
};

bool compare(Node* a,Node* b)
{
    return a->sum > b->sum;
}
void total(Node* root)
{  if(root->child.size()==0)
    { root->sum=0;
      return;
    }
    int mod=1000000007;
    for(int i=0;i<root->child.size();i++)
      total(root->child[i]);

    if(root->child.size()==1)
    { root->sum=root->child[0]->sum+1;
      return;
    }
    sort(root->child.begin(),root->child.end(),compare);

    root->sum=0;
    for(int i=0;i<root->child.size();i++)
    {
        root->sum = (root->sum +(((root->child[i]->sum)*(i+1))%mod +(i+1))%mod ) % mod;
    }

    for(int i=0;i<root->child.size();i++)
    {
        delete(root->child[i]);

    }
    root->child.erase(root->child.begin(),root->child.end());
}
int main() {
	int t;
  cin>>t;
  int mod=1000000007;

 while(t--)
 {  int n,x;
    cin>>n>>x;
  Node* arr[n];
  for(int i=0;i<n;i++)
      arr[i]=NULL;

  Node* root=new Node();
   root->key=1;
  arr[0] = root;

//  Node* temp=new Node();
//   temp->key=2;
//  arr[0]->child.push_back(temp);

 //cout<<arr[0]->child[0]->key<<" ";

   for(int i=0;i<n-1;i++) // n-1 edges
      { int a,b;
        cin>>a>>b;
        if(arr[b-1]==NULL)
       { Node* temp=new Node();
        temp->key=b;
        arr[b-1]=temp;
        arr[a-1]->child.push_back(temp);
       }

      }

      total(root);
      long long int ans=((x*root->sum)%mod+x)%mod;
      cout<<ans<<"\n";

      delete(root);
//for(int j=0;j<n;j++)
// { cout<<arr[j]->key<<" ";
//     for(int i=0;i<arr[j]->child.size();i++)
//  { cout<<arr[j]->child[i]->key<<" ";
//  }
//  cout<<"\n";
// }

 }
	return 0;
}
