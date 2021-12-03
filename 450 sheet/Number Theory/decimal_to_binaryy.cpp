#include<bits/stdc++.h>
using namespace std;

//  for numbers greater than 1023 whose binary representation 
//  exceeds 32 bit use arrays or string to store digits

void using_arrays_bitwise(int n){
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
    for(auto j : binary)
        cout<<j;
    cout<<"\n";
}

void using_arithmetic(int n)  // school method
{   int binary=0;
    int i=0;
    while(n!=0)
    {  
        int digit=n%2;                      
        n=n/2;                               

        binary += digit*pow(10,i);       // reverse
        i++;                                
    }

    cout<<binary<<"\n";
}
void using_bitwise(int n){
    int binary=0;
    int i=0;
    while(n!=0)
    {  
        int digit=n&1;           // returns last bit           
        n=n>>1;                  // removes last bit

        binary += digit*pow(10,i);       // reverse
        i++;                                
    }

    cout<<binary;
    cout<<"\n";
}

int main()
{
    int n;
    cin>>n;
    using_arithmetic(n);
    using_bitwise(n);
    using_arrays_bitwise(n);
}