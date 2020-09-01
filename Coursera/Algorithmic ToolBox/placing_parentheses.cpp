#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long a, long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {

  }
}
void min_max(int j,int k,const string &exp,vector<vector<long long>> &m,vector<vector<long long>> &M )
{ int n=(exp.size()/2)+1;
char op[n-1];
int y=0;
for(int x=0;x<exp.size();x++)
{
    if(x%2!=0)
    { op[y]=exp[x];
        y++;
    }
}

long long min=0,mint,max=0,maxt;
    for(int i=j;i<=k-1;i++)
    { long long a,b,c,d;
       a=eval(m[j][i],m[i+1][k],op[i]);
       b=eval(m[j][i],M[i+1][k],op[i]);
       c=eval(M[j][i],M[i+1][k],op[i]);
       d=eval(M[j][i],m[i+1][k],op[i]);
       if(i==j){ min=std::min(std::min(std::min(a,b),c),d); }
         mint=std::min(std::min(std::min(a,b),c),d);
       if(min>mint){ min=mint;}
        if(i==j){ max=std::max(std::max(std::max(a,b),c),d); }
         maxt=std::max(std::max(std::max(a,b),c),d);
       if(max<maxt){ max=maxt;}
    }
m[j][k]=min;
M[j][k]=max;
}
long long get_maximum_value(const string &exp) {
 int n=(exp.size()/2)+1;
 vector< vector<long long> > m(n, vector<long long>(n)), M(n, vector<long long>(n));
 int i=0;
 for(int j=0;j<n;j++)
 {
     m[j][j]=int(exp[i])-48;
     M[j][j]=int(exp[i])-48;
     i=i+2;
 }
 for(int j=0;j<n;j++)
 { for(int k=0;k<n-j;k++)
    { if(k!=k+j)
        {min_max(k,k+j,exp,m,M);}
    }

 }


  return M[0][n-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
