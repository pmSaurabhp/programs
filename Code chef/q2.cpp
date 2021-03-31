// https://www.codechef.com/LTIME91B/problems/SWAP10HG

#include <iostream>
using namespace std;

void freq_calc(string str,int freq[],int n)
{
	    for(int i=0;i<n;i++)
	      { freq[str[i]-'0']++; }
}
int main() {
	int t;
	cin>>t;
	while(t--)
    { int n,flag=0,count_swaped_1=0;;
      cin>>n;
      string a,b;
      int f1[2]={},f2[2]={};

        cin>>a;
        cin>>b;

      freq_calc(a,f1,n);
      freq_calc(b,f2,n);

      if(f1[0]==f2[0]&&f1[1]==f2[1])  //  case1: f1==f2
      { for(int i=0;i<n;i++)
            { if(a[i]!=b[i])           // case 2:  a 10    or   a 010
                { if(a[i]=='1')        //          b 01         b 100
                    { if(f1[0]!=0)
                        { f1[0]--;
                          count_swaped_1++;
                        }
                      else{
                        flag=1;
                        break;
                      }
                    }
                    else // a[i]==0
                    {
                        if(count_swaped_1!=0&&f1[1]!=0)
                           {f1[1]--;
                              count_swaped_1--;
                           }
                      else
                      { flag=1;
                        break;
                      }
                    }
                }

              else{
                f1[a[i]-'0']--;
              }
            }

      }
      else{
        flag=1;
      }

      if(flag==0)
        cout<<"Yes\n";
      else
        cout<<"No\n";


    }
	return 0;
}
