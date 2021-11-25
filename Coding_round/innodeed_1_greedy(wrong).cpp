	// wasted 1 day to apply this
	// cannot be solved by greedy

// input 121    o/p  2
// 121 = aba , au    o/p 2 decoding patterns

// input 12345   o/p 3
//   abcde  , lcde , awde
	int CountWays(string str){
		    int c=1;
		    char *temp=&str[0];
		    if(*temp=='0')
		     return 0;
		   int i=0;
		   vector<pair<int,int>> index;
   while(*temp!='\0')
   {  if(*(temp)=='0' )
      {   int x= (*(temp-1)-'0')*10 + *temp-'0';
        if(x>26)
            return 0;
      }
     if(*(temp+1)!='\0'&& *temp!='0' && *(temp+1)!='0' && *(temp+2)!='0')
     { int x= (*temp-'0')*10 + *(temp+1)-'0';   // input 120210  o/p 1
         if(x<=26)
         { c++;
           index.push_back(make_pair(i,i+1));
          // cout<<x<<" ";
         }
      }
    i++;
     temp++;
   }
  int s=0;
   for(int j=0;j<index.size();j++)
   {  int alag=0;
       for(int k=j+1;k<index.size();k++)
      { if(index[j].second!=index[k].first)
            alag++;
        else if(j!=0)
         s++;
      }
      //cout<<(pow(2,alag)-1)<<" ";
      c+=pow(2,alag)-1;
   }
   return c-s;
		}
