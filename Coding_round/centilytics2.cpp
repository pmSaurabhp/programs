// i/o  bad
// 0/p  6

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int subsequence(string str,unordered_map<char,int> vowel,string store,int n)
{
   if(n==0)
   {  if(store.size()==1 || store.size()%2==0)
         return 1;
       else{
            int k=0,v=0,f=0;
         for(int i=0;i<store.size();i++)
        {  if(vowel[store[i]]==0)
              { if(f==0)
                  k++;
                else
                    k--;
              }
            else
             { v++;
               f=1;
             }

        }

        if(k==0 && v==1)
            { // cout<<store<<"v=1"<<"\n";
                return 0;
            }
        else
            { // cout<<store<<"\n";
                return 1;
            }
       }
   }
    int c1=0,c2=0;
    c1 = subsequence(str,vowel,store,n-1); // exclusive

    store.push_back(str[n-1]);
    c2 = subsequence(str,vowel,store,n-1); // inclusive

    return c1+c2;
}
int main()
{ int t;
 cin>>t;
  unordered_map<char,int> vowel={ {'a',1},{'e',1},{'i',1},{'o',1},{'u',1} };
 while(t--)
 {
     string str,store;
     cin>>str;

    int c=subsequence(str,vowel,store,str.size()) - 1;

     cout<<c<<"\n";

 }

}
