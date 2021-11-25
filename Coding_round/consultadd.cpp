#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(char s1,char s2)
{ return s1>s2;
}

int main()
{  string s;
   cin>>s;
    int n;
    cin>>n;

    sort(s.begin(),s.end(),compare);

    int c=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==s[i+1])
           { if(c<n)
               c++;
              else
              { int j=i+2;
                while(s[i+1]==s[j])
                { j++;
                }

                char temp=s[i+1];
                s[i+1]=s[j];
                s[j]=temp;
              }

           }
        else
        { c=1;
        }
    }
    cout<<s;

}
