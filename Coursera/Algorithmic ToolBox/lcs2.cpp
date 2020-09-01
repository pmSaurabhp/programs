#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;


int lcs2(vector<int> &a, vector<int> &b) {

int n=a.size()+1,m=b.size()+1;
int d[n][m];
vector<int> c;

for(int i=0;i<n;i++)
{
    d[i][0]=0;
}
for(int i=0;i<m;i++)
{
    d[0][i]=0;
}

for(int i=1;i<n;i++)
{  for(int j=1;j<m;j++)
   {  if(a[i-1]==b[j-1])
        {
          d[i][j]=d[i-1][j-1]+1; //  d[i][j]=max(d[i][j-1]+1,d[i-1][j]+1); fails at a=2 & b={2,2}
        }        // diagonal
       else{
        d[i][j]=max(d[i][j-1],d[i-1][j]);
       }         // from max of left & up
   }
}

//  print set of common sequence

//int i=n-1,j=m-1;
//while(i!=0||j!=0)
//{
//
//        if(a[i-1]==b[j-1])
//        { c.push_back(a[i-1]);
//          i--;
//          j--;
//        }
//       else{
//        if(d[i][j]==d[i-1][j])
//        {
//            i--;
//        }
//        else{
//            j--;
//        }
//       }
//
//}
//reverse(c.begin(),c.end());
//for(int k=0;k<d[n-1][m-1];k++)
//{
//    std::cout<<c[k]<<" ";
//}
return d[n-1][m-1];
}
int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
