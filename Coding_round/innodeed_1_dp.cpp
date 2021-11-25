https://leetcode.com/problems/decode-ways/
class Solution {
public:
    	int decode_dp(string str)
	{   int n = str.size();
	   int dp[n+1];
	    dp[n]=1;
        if(str[n-1]!='0')
            dp[n-1]=1;
        else          // '110'
         dp[n-1]=0;

	    for(int i=n-2;i>=0;i--)
	    { if(str[i]=='0')
	         dp[i]=0;
	       else
           {    if(str[i+1]=='0')
                    dp[i] = dp[i+2];
                else
                { dp[i] = dp[i+1];

                    if (str[i] == '1' || (str[i] == '2' && str[i+1] < '7'))
                         dp[i] = dp[i] + dp[i+2];
                 }

	        }
	    }
	    //for(int i=0;i<n+1;i++)
        //   cout<<dp[i]<<" ";
	    return dp[0];
	}
    int numDecodings(string str) {
        if(str[0]=='0')   // 0124
		      return 0;

		  for(int i=0;i<str.size()-1;i++)
		   {int combine=(str[i]-'0')*10 + str[i+1]-'0';
		       if(combine == 0 || (str[i+1]=='0' && combine>26 ))  // 100  , 70
		            return 0;
		   }
        return decode_dp(str);
    }
};
