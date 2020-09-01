#include <iostream>
#include <string>

using namespace std;
bool comp(int a,int b)
{
    return (a<b);
}
int edit_distance(const string &str1, const string &str2) {
int s1=str1.size()+1,s2=str2.size()+1;
int d[s1][s2];

for(int i=0;i<s1;i++)
{
    d[i][0]=i;
}
for(int i=0;i<s2;i++)
{
    d[0][i]=i;
}

for(int i=1;i<s1;i++)
{  for(int j=1;j<s2;j++)
   { int diff;
       if(str1[i-1]==str2[j-1])
        { diff=0;
        }
        else{
            diff=1;
        }
        d[i][j]=min(d[i][j-1]+1,d[i-1][j]+1);

        d[i][j]=min(d[i][j],d[i-1][j-1]+diff);

   }

}
return d[s1-1][s2-1];
}

int main() {
  string str1;
  string str2;
  cin >> str1 >> str2;
  cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
