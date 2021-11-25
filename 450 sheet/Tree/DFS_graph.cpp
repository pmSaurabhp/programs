#include <iostream>
#include <vector>
using namespace std;

class Node                                 // n-ary  also has vector of childs
{public:                                   // graph  has vector of childs and visited
    int val;
    vector<Node*> adjacency_list;
    int visited;
    Node(int a)
    {   val=a;
        visited=0;
    }
};
void DFS(Node *root)// Graph DFS Traverasal
{   root->visited=1;
    cout<<root->val<<" ";
    if(root->adjacency_list.size()==0)
        return;
    for(int i=0;i<root->adjacency_list.size();i++)
    {
        if(root->adjacency_list[i]->visited==0)
            {

                DFS(root->adjacency_list[i]);
            }
    }
}
int main() {
	Node *A=new Node(1);
	Node *B=new Node(2);                          //           1
	Node *C=new Node(3);                          /*        / \  \              */
	Node *D=new Node(4);                          //        2   3  4
	Node *E=new Node(5);                          //       /  \    /
	Node *F=new Node(6);                          //      5    6  7
	Node *G=new Node(7);

	A->adjacency_list.push_back(B);
	A->adjacency_list.push_back(C);
	A->adjacency_list.push_back(D);
	B->adjacency_list.push_back(A);
	B->adjacency_list.push_back(E);
	B->adjacency_list.push_back(F);
	C->adjacency_list.push_back(A);
	D->adjacency_list.push_back(A);
	D->adjacency_list.push_back(G);
	E->adjacency_list.push_back(B);
	F->adjacency_list.push_back(B);
	G->adjacency_list.push_back(D);


	DFS(A);
	return 0;
}




