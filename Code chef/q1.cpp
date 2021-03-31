// https://www.codechef.com/LTIME91B/problems/THREE
#include <iostream>
#include <string>
using namespace std;
void freq_calc(string str,int freq[])
{

	    int n=str.size();
	   // int freq[26]={};

	    for(int i=0;i<n;i++)
	      { freq[str[i]-'a']++;

	      }
}
int main() {
 int t;
 cin>>t;

  while(t--)
  {   string str;
      cin>>str;
      int freq[26]={};
      freq_calc(str,freq);
      int c=0,sum=0;
      for(int i=0;i<26;i++)
            sum+=freq[i];
      for(int i=0;i<26;i++)
      {
          if(freq[i]>=2 && sum>=3)
          { c++;
              sum-=3;
              freq[i]-=2;
            i--;           //  str : ccccde
          }

      }
      cout<<c<<"\n";
  }




	return 0;
}
