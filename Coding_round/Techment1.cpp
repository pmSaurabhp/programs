// for questions https://mail.google.com/mail/u/0/?tab=rm&ogbl#inbox/FMfcgzGkXSWwGMRFrPrkBbxhTGQBHQjt
#include <iostream>
#include <String>
using namespace std;
int main()
{  string s1="techmentforallsks", s2="allskfortechments";

   int count[26];
for(int i=0;i<26;i++)
   count[i]=0;

     for(int i=0;i<s1.size();i++)
   {   count[s1[i]-'a']++;
     }
     for(int i=0;i<s2.size();i++)
    {   count[s2[i]-'a']--;
    }
  int f=0;
    for(int i=0;i<26;i++)
   {  if(count[i] !=0)
        { f=1;
           break;
        }
   }
  if(f==0)
     cout<<"Yes";
  else
     cout<<"No";
}
