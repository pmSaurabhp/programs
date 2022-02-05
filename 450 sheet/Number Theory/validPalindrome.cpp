
// https://leetcode.com/problems/valid-palindrome/

    bool isAlphaNumeric(char s)
    {
        if(!((s>='a' && s<='z') || (s>='A' && s<='Z') || (s>='0' && s<='9')) )
            return false;
        return true;
    }
    char toLowerCase(char s)
    {
        if((s>='A' && s<='Z'))
                {
                    s=s-'A'+'a';
                }
        return s;
    }
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        
        while(i<=j)
        {
            if(!isAlphaNumeric(s[i]))
            {i++;
             continue;
            }
            if(!isAlphaNumeric(s[j]))
            {j--;
             continue;
            }
         
            if(s[i]>='0' && s[i]<='9')
            {
                if(s[i]!=s[j])
                    return false;
            
            }
            else{
                s[i]=toLowerCase(s[i]);
                s[j]=toLowerCase(s[j]);
                
                if(s[i]!=s[j])
                    return false;
            }
            i++;
            j--;
        }
        return true;
    }
