// https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.size()==0)
            return 0;
        if(s.size()==1)
            return 1;
        unordered_map<char,int> umap;

        for(int i=0;i<s.size();i++)
            umap.insert(make_pair(s[i],-1));

        int j=0,k=0,l=-1,ltemp;
        for(int i=0;i<s.size();i++)
        {
            if(umap[s[i]]==-1)
            {umap[s[i]]=i;
             k=i;
           //  cout<<"u";
            }
            else
            { if(j<=umap[s[i]]  && umap[s[i]] <=k)
                j=umap[s[i]]+1;

              k=i;
              umap[s[i]]=i;
            // cout<<"d";
            }
             ltemp=k-j+1;
             if(l<ltemp)
                 l=ltemp;
           // cout<<ltemp<<" ";
        }

      // cout<<"\n"<<j<<" "<<k;
        return l;
    }
};
//class Solution {     // my wrong solution in 1st try
//public:
//    int lengthOfLongestSubstring(string s) {
//
//        if(s.size()==1)
//            return 1;
//        unordered_map<char,int> umap;
//
//        for(int i=0;i<s.size();i++)
//            umap.insert((make_pair(s[i],-1)));
//
//        unordered_map<char,int> temp=umap;
//
//       // for(auto i : temp)
//         //   cout<<i.first<<" "<<i.second<<"\n";
//        int c=0;
//        int t=0;
//        for(int i=0;i<s.size();i++)
//        {
//          if(temp[s[i]]==-1)
//          { t++;
//            temp[s[i]]=i;
//           if(i==s.size()-1)
//           { if(t>c)
//              c=t;
//           }
//          }
//          else
//          { if(t>c)
//              c=t;
//           t=0;
//
//           for(int j=0;j<=temp[i];j++)
//              temp.erase(temp[j]);
//
//           i--;
//
//          }
//        }
//        return c;
//    }
//};
