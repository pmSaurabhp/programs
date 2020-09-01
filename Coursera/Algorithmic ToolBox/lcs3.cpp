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
int lcs3(vector<int> &a, vector<int> &b,vector<int> &c) {

int n=a.size()+1,m=b.size()+1;
int d[n][m];
vector<int> seq;

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
if(d[n-1][m-1]==0)
{
    return 0;
}
int i=n-1,j=m-1;
while(i!=0||j!=0)
{

        if(a[i-1]==b[j-1])
        { seq.push_back(a[i-1]);
          i--;
          j--;
        }
       else{
        if(d[i][j]==d[i-1][j])
        {
            i--;
        }
        else{
            j--;
        }
       }

}
reverse(seq.begin(),seq.end());
int result=lcs2(seq,c);
return result;
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  int result1,result2;
 result1=lcs3(a, b, c);
 result2=lcs3(a,c,b);
 if(result1>=result2)
 { std::cout<<result1;
 }
 else{
    std::cout<<result2;
 }
}
