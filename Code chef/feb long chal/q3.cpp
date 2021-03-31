#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
void team_name(vector<string> str)
{
    unordered_map<string,int> store;

    for(int i=0;i<str.size();i++)
    {
       store[str[i]]=1;
    }

     int c=0;

    for(int i=0;i<str.size();i++)
    {
        for(int j=i+1;j<str.size();j++)
       {  string t1=str[j],t2=str[i];
          t1[0]=str[i][0];
          t2[0]=str[j][0];

          if(store[t1]==0&&store[t2]==0)
            c+=2;

       }
    }

    cout<<c<<"\n";
}
int main() {

int t;
cin>>t;
 while(t--)
 { int n;
   cin>>n;
 vector<string> str(n);
  for(int i=0;i<n;i++)
   cin>>str[i];

   team_name(str);

 }
 return 0;
}
