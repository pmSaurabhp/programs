// question
// there are N number of sections in examination paper
// each element of array a[] is the number of questions in one section
// find speed x of student so that he completes paper in H hours

#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &arr, int h,int mid)
{  int c=0;
    float j=mid;
   for(int i=0;i<arr.size();i++)
   {   if(arr[i]<mid)
         c+=1;
        else{
            float k=arr[i]/j;    // c+=ceil(arr[i]/mid)   wrong  arr[i] & mid both are int
             c+=ceil(k);
        }
        
      //cout<<c<<" "<<mid<<ceil(arr[i]/mid)<<"\n";
   }
 
   if(c<=h)
     return true;
   else
   return false;
}

int main() {
    
    int n,h;
    cin>>n;
    cin>>h;
    
    vector<int> arr(n);
     for(int i=0;i<n;i++)
        cin>>arr[i];
	sort(arr.begin(),arr.end());  // first sort
   
    int min=1,max=arr[n-1];
    // FFFFTTT    last F
    while(min<max)
    {	
        int mid=min+(max-min)/2;   
        //cout<<mid;
        if(isPossible(arr,h,mid)) 	
           { max=mid;    
            //cout<<mid;
           }
        else
        {  
            min=mid+1;        
        }
    }
    cout<<min;
	return 0;
}
