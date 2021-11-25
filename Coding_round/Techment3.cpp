#include <iostream>
#include <string>
using namespace std;
int main()
{    string s1="techment", s2="champions",s3;     //  s3  :  uncommon string

   int count[26]={0};

for(int i=0;i<26;i++)
   count[i]=0;

     for(int i=0;i<s1.size();i++)
   {   count[s1[i]-'a']=1;
     }
     for(int i=0;i<s2.size();i++)
    {   if(count[s2[i]-'a']!=1)
         {  s3.push_back(s2[i]);
          }
    }


for(int i=0;i<26;i++)
   count[i]=0;

  for(int i=0;i<s2.size();i++)
   {   count[s2[i]-'a']=1;
     }
     for(int i=0;i<s1.size();i++)
    {     if(count[s1[i]-'a']!=1)
         {  s3.push_back(s1[i]);
          }
    }
  if(s3.size()==0)
    cout<<"-1";
 else
   cout<<s3;
}
