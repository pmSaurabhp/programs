// https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=1
// https://www.youtube.com/watch?v=YTTdLgyqOLY&t=53s
#include <bits/stdc++.h>
using namespace std;

// T(n)= n*logn + log(n)*(n) 
//	   = n*logn
bool isPossible(vector<int> &stalls, int k,int dist)
{
    int cowsPlaced=1;     // 1st cow is already placed at index 0
    int i=0;              // position of one cow at 0
    for(int j=1;j<stalls.size();j++)
    {
        if(stalls[j]-stalls[i]>=dist)   // placed another cow at index j
        {
            cowsPlaced++;   
            i=j;                        // make j as position of cow and search for next cow
        }
        if(j==stalls.size()-1 && cowsPlaced<k)   
        { 
            return false;
        }
    }
    return true;
}
// with framework
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());  // first sort
   
    int min=0,max=stalls[stalls.size()-1];
    // FFFFTTT    last F
    while(min<max)
    {	
        int mid=min+(max-min+1)/2;   // we are changing high so +1 
        
        // if mid is possible all numbers left to it are also possible
        if(!isPossible(stalls,k,mid)) 	
            max=mid-1;     
        else
        {  
            min=mid;        
        }
    }
    return min;
}
// without framework
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());  // first sort
   
    int min=0,max=stalls[stalls.size()-1];
    
    int ans;
    while(min<=max)
    {	
        int mid=min+(max-min)/2;

        if(isPossible(stalls,k,mid))
        { 	ans=mid;
            min=mid+1;     // mid distance between cows is possible we want maximum distance
                           // so we move up and make search space   mid+1 - max
        }
        else
        {
            max=mid-1;      // mid distance between cows is not possible
                            // so distance between mid - max is also not possible
                            // so we make search space   min - mid-1   
        }
    }
    return ans;
}

int main()
{  
    return 0;
}