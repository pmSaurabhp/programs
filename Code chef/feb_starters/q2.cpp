#include <iostream>
#include <vector>

using namespace std;

int main()
{ int t;
  cin>>t;

 while(t--)
 {  int n;
    cin>>n;
    int q[n];

    for(int i=0;i<n;i++)
        cin>>q[i];

    vector<vector<int>> s(n);

    for(int i=0;i<n;i++)
    {
        int l;
        cin>>l;
        vector<int> temp(l);

        for(int j=0;j<l;j++)
        {
            cin>>temp[j];
        }
        s[i]=temp;
    }

    long long int time=0;    // i did only one mistake int time = 0  :(  ( long long )
    for(int i=0;i<n;i++)
    {  for(int j=0;j<s[i].size();j++)
       {  if(j!=0)
            {
                time+= s[i][j]-q[i];
            }
            else
                time+=s[i][j];
       }

    }

  cout<<time<<"\n";
 }

}
