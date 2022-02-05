// https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/

// find all triplets equal to given value
// https://www.codingninjas.com/codestudio/problems/triplets-with-given-sum_893028?leftPanelTab=1
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> findTriplets(vector<int>arr, int n, int k) 
{
	set<vector<int>> unq_set;   // to get unique arrays
    sort(arr.begin(),arr.end());
   
    for(int i=0;i<n;i++)
    { int need=k-arr[i];
      int a=i+1,b=n-1;
      vector<int> temp;
      temp.push_back(arr[i]);
        while(a<b)
        {
            if(arr[a]+arr[b]==need)
            { 
               temp.push_back(arr[a]);
                temp.push_back(arr[b]);
                unq_set.insert(temp);
             
                temp.erase(temp.begin()+1,temp.end());
             	a++;
             	b--;
             	
            }
            if(arr[a]+arr[b]>need)
                b--;
             if(arr[a]+arr[b]<need)
                 a++;
        }
    }

     vector<vector<int>> ans;
     for(auto i:unq_set)    
        ans.push_back(i);
    
    return ans;
}
int main()
{
    vector<int> arr{-200,162 ,4 ,18, 1, 15, 28, 8, -60, 12, 10, -200, 165, 14};

    vector<vector<int>> ans=findTriplets(arr,arr.size(),-20);

    for(auto i:ans)
    { for(auto j:i)
        cout<<j<<" ";
      cout<<"\n";
    }
        
}