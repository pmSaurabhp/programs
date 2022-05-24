// https://leetcode.com/problems/complement-of-base-10-integer/submissions/

#include <bits/stdc++.h>
using namespace std;
    vector<int> decimalToBinary(int n)
 {
    vector<int> binary;
    int i=0;
    while(n!=0)
    {  
        int digit=n&1;           // returns last bit           
        n=n>>1;                  // removes last bit

        binary.push_back(digit);       
        i++;                                
    }
    
    reverse(binary.begin(),binary.end());
    
    return binary;
}
int binaryToDecimal(vector<int> bin)
{   int decimal=0;
    int i=bin.size()-1,j=0;
    while(i>=0){

        if(bin[i]==1)
            decimal += pow(2,j);
        i--;
        j++;
    }
    
    return decimal;
}
    int bitwiseComplement(int n) {
        if(n==0)
            return 1;
            
        vector<int> binary=decimalToBinary(n);
        int i=binary.size()-1;
        while(n!=0)
        { 
           n = n>>1;
            if(binary[i]==1)
                binary[i]=0;
            else
                binary[i]=1;
         i--;
        }
            
        return  binaryToDecimal(binary);
    }
    int main()
{
   // int n=10;
 
    //bitwiseComplement(n);
    int n=3;
   vector<int> res= decimalToBinary(n);
   for(int i=31;i>=0;i--)
    cout<<res[i];
}