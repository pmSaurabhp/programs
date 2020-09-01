#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}
int places(int x){
int c=0;
while(x!=0)
    { x=x/10;
        c++;
    }
    return c;
}
void largest(vector<int> a)
{vector<int> b;

 while(a.size()>0)
 {   int max=a[0];
 int j=0;
    for(int i=1;i<a.size();i++)
    { int pa=places(a[i]),pm=places(max);
      int ax=a[i],am=max,sum1,sum2;

            for(int j=0;j<pm;j++)
            {
                ax=ax*10;
            }
            sum1=ax+am;

            ax=a[i];
             for(int j=0;j<pa;j++)
            {
                am=am*10;
            }
            sum2=ax+am;

        if(sum1>=sum2){
            max=a[i];
            j=i;
        }
    }
     b.push_back(a[j]);
    a.erase(a.begin()+j);
 }
   for (size_t i =0; i < b.size(); i++) {
    std::cout<< b[i];
  }
}
void largest_num(vector<int> a){
 vector<int> b;

 while(a.size()>0)
 {   int max=a[0];
 size_t j=0;
    for(size_t i=1;i<a.size();i++)
    { int pa=places(a[i]),pm=places(max);

        if(pa==pm&&a[i]>max)
            {
              max=a[i];
              j=i;
            }
        else if(pa>pm)
            { int x=a[i],y=max;
                for(int i=0;i<pa-pm;i++)
                { x=x/10;  }

                if(x>y)
                {
                    max=a[i];
                    j=i;
                }
               if(x==y)
                {
                 int c;
                x=a[i];  y=max;
                 for(int i=1;i<pa-pm;i++)
                 { x=x/10;  }
                 c=x%10;
                 for(int i=1;i<pm;i++)
                 { y=y/10;  }
                 if(c>=y)
                 { max=a[i];
                    j=i;
                 }

               }
            }
            else{// pa<pm
                int x=a[i],y=max;
                for(int i=0;i<pm-pa;i++)
                { y=y/10;  }

                if(x>y)
                {
                    max=a[i];
                    j=i;
                }
               if(x==y)
                {
                int c;  x=a[i]; y=max;
                for(int i=1;i<pm-pa;i++)
                { y=y/10; }
                c=y%10;
                for(int i=1;i<pa;i++)
                { x=x/10; }
                if(c<=x)
                { max=a[i];
                j=i;
                }
                }
            }
    }
    b.push_back(a[j]);
    a.erase(a.begin()+j); //  a.erase(j); does not works
 }
for (size_t i =0; i < b.size(); i++) {
    std::cout<< b[i];
  }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  // largest_num(a);  seing all cases and make an algorithm for each case which is very hectic and
   largest(a);  // simpler algorithm
}
