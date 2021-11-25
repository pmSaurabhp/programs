// to find minimum element  in stack after each pop operation
#include<iostream>
#include <stack>
using namespace std;

int main()
{ stack<int> mystack;
  stack<int> min_stack;

  int n=5;
  for(int i=0;i<n;i++)
  { int a;
    cin>>a;
    mystack.push(a);
    if(min_stack.empty())
        min_stack.push(a);
    else
    { if(min_stack.top()>a)
        min_stack.push(a);
    }
  }

   for(int i=0;i<n;i++)
   {
       cout<<"Minimum Element is "<<min_stack.top()<<"\n";
       if(mystack.top()==min_stack.top())
            min_stack.pop();
       mystack.pop();
   }

}
