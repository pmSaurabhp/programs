https://leetcode.com/problems/decode-ways/
// input 121    o/p  2
// 121 = aba , au    o/p 2 decoding patterns

// input 12345   o/p 3
//   abcde  , lcde , awde

// input 12134150  o/p 0
// input 12315    o/p 6
// input 47203142   o/p 2
#include<iostream>
#include <string>

using namespace std;

int decode(string str,int i)
 { if(i>=str.size()-1)
        return 1;

     int sum;
     if(str[i+1]=='0')    // _ _ 20_ _
      sum = decode_recursion(str,i+2);
     else
     { sum = decode_recursion(str,i+1);

        int combine=(str[i]-'0')*10 + str[i+1]-'0';
        if(combine <= 26)
        sum = sum +  decode_recursion(str,i+2);

     }
    return sum;
}
int main()
{ string str;
    cin>>str;

  cout<<decode(str,0);
}
