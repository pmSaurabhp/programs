// output index of element at index i => arr[i]= arr[j] * arr[k] where j&k < i 
// j can be equal to k

#include <bits/stdc++.h>
using namespace std;

int findNum(vector<int> arr)
{ unordered_map<int, int> ump;
  int n=arr.size();
    
    for(int i=0;i<n;i++)
    { 	ump.insert(make_pair(arr[i], 1 ));
   
        for(int j=0;j<i;j++)
        { 
        if(arr[j]!=1 && arr[i]%arr[j]==0 && ump.find(arr[i]/arr[j])!=ump.end() )
            return i;
        }
    }
    return -1;
}
int main() {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	cout<<findNum(arr);
	return 0;
}
