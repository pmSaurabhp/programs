
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> find_lps(string s)
{ int n=s.size();

	    vector<int> lps(n);
	    int i,j,max=0;   // 0 1 2 3 4 5 6 7 8 9 10
	    i=0;  j=1;       // a b c a b c d a b c e
	    lps[0]=0;
                        //  0 1 2 3 4 5 6 7 8 9 10
                     // lps 0 0 0 1 2 3 0 1 2 3 0

	    while(j<n)
	    {
	        if(s[i]==s[j])
	        {  lps[j]=i+1;
	            i++;   j++;
	        }
	        else
	        {               // here i is decresed and j is ++
	            if(i==0)
	            { lps[j]=0;
	               j++;
	            }
	            else
	            {   i--;
	                i=lps[i];  // then check pat[i]==pat[j]
	            }
	        }

	    }

    return lps;

	}
void kmp(string s,string pat)
{ int n,m,i,j;
   n=s.size();
   m=pat.size();
   i=0; j=0;
   vector<int> lps(m),res;
   lps=find_lps(pat);             // a d e a b c g a b c d      i never decreases
                                  //             i
   while(i<n)                     // a b c d        then j=0 ,i++ when pattern
   { if(s[i]==pat[j])             //       j        does not contain repeated subseuence like in a b d a b    ab is repeated
     { i++; j++;
      if(j==m)                         //  a b a b a b d
      {  res.push_back(i-j+1);         //          i
           j=lps[j-1];
      }                                //  a b a b d                                                      a b a b d
     }                                 //  0 0 1 2 0    then j--  , j=lps[j] so j=2  check a[i]==pat[j]   0 0 1 2 0
    else{                              //          j                                                          j
        if(j==0)
            i++;
        j--;
        if(j<0)
            j=0;

        j=lps[j];
      }
   }

   for(int k=0;k<res.size();k++)
     cout<<res[k]<<" ";
}
int main() {
string s,pat;
cin>>s;
cin>>pat;

kmp(s,pat);

return 0;
}
