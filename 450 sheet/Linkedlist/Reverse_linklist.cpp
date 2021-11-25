#include<iostream>

using namespace std;

class Node
{public:
    int val;
    Node *next;
    Node()
    {
        next=NULL;
    }
    Node(int a)
    {   val=a;
        next=NULL;
    }
};
void rev(Node *head)
{
    Node *new_h=NULL;  // i have made new_head and we start connecting all nodes to this new_head in backward direction
    Node *temp;
    while(head!=NULL)         // predecessor , current and sucessor can also be used as used in insert and delete
    {  temp=head;             // to reverse the direction of pointers
        head=head->next;
        temp->next=new_h;
        new_h=temp;
    }


    temp=new_h;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
int main()
{   Node *a1=new Node(1);
    Node *a2=new Node(2);
    Node *a3=new Node(3);
    Node *a4=new Node(4);
    Node *a5=new Node(5);

    Node *head=a1;
    a1->next=a2;
    a2->next=a3;
    a3->next=a4;
    a4->next=a5;
    a5->next=NULL;

    rev(head);
}
