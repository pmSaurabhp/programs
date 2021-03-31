#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int t;
  cin>>t;

  while(t--)
  { int n;
   cin>>n;

   vector<int> arr(n);
   for(int i=0;i<n;i++)
    cin>>arr[i];

  int c=0;
  for(int i=0;i<n;i++)
  { c+=arr[i];
  }
  if(c%2==0)
        cout<<"1\n";
    else
     cout<<"2\n";


  }
}
