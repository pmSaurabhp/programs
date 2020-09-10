#include <algorithm>
#include <iostream>
#include <vector>
#include<queue>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using namespace std;
class Node;

class Node {
public:
    int key;
    Node *parent;
    vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

int height(Node *nodes)
{  int depth=0;
    for(int i=0;i<nodes->children.size();i++)
    {
        depth=max(depth,height(nodes->children[i]));
   }
//cout<<nodes->children[0]->key;        // (*nodes).key = nodes->key
return depth+1;
}

//Replace this code with a faster implementation
int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);

  int maxHeight = 0;
  int n,root_index;
  cin >> n;

  vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    cin >> parent_index;
     if (parent_index >= 0)
       nodes[child_index].setParent(&nodes[parent_index]);
     if(parent_index==-1)
     { root_index=child_index; }
    nodes[child_index].key = child_index;
  }
//Replace this code with a faster implementation
  for (int leaf_index = 0; leaf_index < n; leaf_index++) {
    int height = 0;
    for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
      height++;
    maxHeight = std::max(maxHeight, height);
 }
  return 0;
}

int main ()
{   int n,root_index;
  cin >> n;

  vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    cin >> parent_index;
     if (parent_index >= 0)
       nodes[child_index].setParent(&nodes[parent_index]);
     if(parent_index==-1)
     { root_index=child_index; }
    nodes[child_index].key = child_index;
  }

//cout<<nodes[root_index].children[1]->key;
//cout<<nodes[root_index].key;
 cout<<height(&nodes[root_index]);

return 0;
//  return main_with_large_stack_space();
}
