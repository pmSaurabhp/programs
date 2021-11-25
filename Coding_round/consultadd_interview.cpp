// interview question

//Given a binary string that represents the target state, find out how many flips are required to convert the same
//size Binary String (with all 0's) to the target state.
//Rules:
//Every time you flip a bit, every bit to the right of it, will also flip automatically (i.e 0->1 & 1->0).
//
//input - 1010
//output - 4
//
//0 0 0 0   initial
//
//1 0 1 0  target
#include<iostream>
#include <string>
using namespace std;

int main()
{  string target;
    cin>>target;

    string s2;
    for(int i=0;i<target.size();i++)
    {
        s2[i]='0';
    }

    int c=0;                                         // 1010
    for(int i=0;i<target.size();i++)                 // 1010   c=2
    {                                                // 0001
        if(s2[i] != target[i])
        { s2[i] = target[i];
            c++;
            for(int i=0;i<target.size();i++)
                cout<<s2[i];
          //  cout<<" "<<c<<"\n";

            for(int j=i+1;j<target.size();j++)
           {
               if(s2[j]=='0' )
                s2[j]='1';
               else
                s2[j]= '0';

           }

        }

    }

    cout<<"Count :"<<c;


}

