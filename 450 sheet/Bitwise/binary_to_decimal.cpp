#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(vector<int> bin)
{   int decimal=0;
    int i=bin.size()-1,j=0;
    while(i>=0){

        if(bin[i]==1)
            decimal += pow(2,j);

        i--;
        j++;
    }
    cout<<decimal<<"\n";
    return decimal;
}
void convert(int n)
{   int decimal=0;
    int i=0;
    while(n!=0){
       int digit= n%10;
       n=n/10;
        if(digit==1)
            decimal += pow(2,i);

        i++;
       
    }
    cout<<decimal<<"\n";
}
int main()
{
    int n;
   // cin>>n;
     vector<int> bin{1,0,1,0};
    //convert(n);
    binaryToDecimal(bin);
    
}