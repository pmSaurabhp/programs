#include <iostream>
#include<vector>
using namespace std;

int maximumGap(vector<int> &A) {

    if(A.size()==1)
      return 0;
    int min_=A[0],max_=A[0];
    for(int i=1;i<A.size();i++)
    { if(min_>A[i])
        min_=A[i];
      if(max_<A[i])
        max_=A[i];
    }

    int gap=(max_-min_)/(A.size()-1);
    if(gap==0)
        return 0;
    int n=max_/gap+1;
    vector<int> max_arr(n,0), min_arr(n,max_);


    for(int i=0;i<n;i++)
    {
        int j=A[i]/gap;
        if(max_arr[j]<A[i])
            max_arr[j]=A[i];

       if(min_arr[j]>A[i] && A[i]!=min_)
            min_arr[j]=A[i];

   }
   for(int i=0;i<n;i++)
   {
       cout<<max_arr[i]<<" ";
   }
   int ans=0,j=1,k=0;
   for(int i=0;i<n-1;i++)
   {

    if(max_arr[k]==0)
       { k++;
        j++;
        continue;
       }
     if(min_arr[j]==max_ && j!=n-1)
       { j++;
        continue;
       }
    if(ans < min_arr[j] - max_arr[k] )
        ans = min_arr[j] - max_arr[k]  ;

    cout<<max_arr[k]<<" "<<min_arr[j]<<" "<<ans<<"\n";
     k++;
     j++;

   }

   return ans;
}

int main()
{  vector<int> A={1,10,5};
   cout<<"\nANS ="<<maximumGap(A);
}
