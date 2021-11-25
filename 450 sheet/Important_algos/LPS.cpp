#include <iostream>
#include <string>

using namespace std;
int find_lps(string s)
{ int n=s.size();

	    int lps[n];
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
	    cout<<"lps : ";
	    for(int k=0;k<n;k++)
        {
            cout<<lps[k]<<' ';
        }
        cout<<'\n';
	    int res = lps[n-1];     //  i/p  abcabcdabce
                                //  o/p :  0

    // Since we are looking for
    // non overlapping parts.
    return res;

	}
int main() {
string s;
cin>>s;

cout<<find_lps(s);
return 0;
}
