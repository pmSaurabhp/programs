// longest pallindromic substring

#include<iostream>                 // brute force O(n^3)
#include <string>                  // dynamic programing  O(n^2)  but O(n^2) space complexity
using namespace std;

int main()
{ string str="xyxraceecarxn";

   int len=0;
   for(int i=0;i<str.size();i++)       // O(n^2)      space O(1)
   {  int temp=0;
      int j;

       for(j=1;j<str.size()-i;j++)
       {
            if(str[i]==str[i+1])     // if pallindrome is even   aeea
            { if(str[i+1+j]==str[i-j] && (i-j)>=0 && (i+1+j)<str.size())
             { temp= 2*j;
             }
            }
            else if(str[i+j]==str[i-j] && (i-j)>=0) //if odd   aea
                { temp= 2*j;
                }
            else
              break;
       }
       if(temp>=len)
        { if(str[i]==str[i+1])
            len=temp+2;
          else
            len=temp+1;
        }
   }
        cout<<len<<" ";
}
