#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

// a string is given and we have sort it  such that
// b , d ,e , 1 , 3 ,5 are considered odd and a,c,e , 2,4,6,8 are conidered even
//  odd comes first ( less priority ) and even comes later (higher priority )
// and integers ( 0 to 9 ) have high priority than characters ( a to z )

// i/p
// 3
// abcd1234
// abcd
// 1234
//
// o/p
// bdac1324
// bdac
// 1324
using namespace std;
class sks{
public:
    char c;
    int priority;

} ;
bool compare_fun(sks s1,sks s2)
{
    return s1.priority<s2.priority;
}

void sort_priority(string str)  // anurag's idea
{
    unordered_map<char,int> dict={ {'b',0},{'d',1},{'f',2},{'h',3},{'j',4},{'l',5},{'n',6},{'p',7},{'r',8},{'t',9},{'v',10},
    {'x',11},{'z',12},{'a',13},{'c',14},{'e',15},{'g',16},{'i',17},{'k',18},{'m',19},{'o',20},{'q',21},{'s',22},{'u',23},
    {'w',24},{'y',25},{'1',26},{'3',27},{'5',28},{'7',29},{'9',30},{'0',31},{'2',32},{'4',33},{'6',34},{'8',35}

    };
    vector<sks> t(str.size());
    for(int i=0;i<str.size();i++)
    {
        t[i].c=str[i];
        t[i].priority=dict[str[i]];
    }

    sort(t.begin(),t.end(),compare_fun);
    for(int i=0;i<str.size();i++)
    {
        cout<<t[i].c;
    }

  cout<<"\n";
}

bool compare_f(char s1,char s2) // my idea bad method + not working
{ int i1=s1,i2=s2;

  if(i1>=97)
  { if(i2>=97)
     { if((i1+1)%2==0)
        { cout<<"1st\n";
            if((i2+1)%2==0)
           return i1<i2;
          else
           return 0;
        }
       else
        {
            cout<<"2nd\n";
            if((i2+1)%2==0)
            return 1;
          else
           return i1<i2;
        }
     }
      else
        return 0;
  }
 else
 { if(i2>=97)
    return 0;
   else
   {  cout<<"3rd\n";
       if(i1%2==0)
        { if((i2)%2==0)
           return i1<i2;
          else
           return 0;
        }
       else
        { if(i2%2==0)
            return 1;
          else
           return i1<i2;
        }

   }

 }
}
int main() {
//Write your code here
int n;
cin>>n;
 while(n--)
 { string str;
   cin>>str;

   sort_priority(str);

 }
 return 0;
}
