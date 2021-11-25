#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(int n,int m,vector<vector<int>> visit)
{
    vector<int> arr(n,0);
 for(int i=0;i<visit.size();i++)                            // O(n^2)
     {
        for(int j=visit[i][0];j<=visit[i][1];j++)
        {  arr[j-1]++;
        }
     }

     int a=arr[0],b=arr[0],c=arr[0];           // also We can sort and then take last 3 value
     int ai=1,bi=1,ci=1;;                      // and this will give O(n*log n)
      for(int i=1;i<arr.size();i++)                         // O(n)
      { if(c<arr[i] || ( c==arr[i] && (b<arr[i] || a<arr[i]) ))
          {
              a=b;
              b=c;
              c=arr[i];

              ai=bi;
              bi=ci;
              ci=i+1;
          }

      }

      vector<int> ans;
      ans.push_back(ai);
      ans.push_back(bi);
      ans.push_back(ci);

      return ans;
}

int main()
{ int t;
  cin>>t;

 while(t--)
 {  int n,m;
    cin>>n>>m;

  vector<vector<int>> visit(m,vector<int>(2));

   for(int i=0;i<m;i++)
     { for(int j=0;j<2;j++)
        { cin>>visit[i][j];
        }
     }

     vector<int> out;
     out=solve(n,m,visit);
     cout<<out[0];
     for(int i=1;i<out.size();i++)
        cout<<" "<<out[i];

     cout<<"\n";
 }

}
