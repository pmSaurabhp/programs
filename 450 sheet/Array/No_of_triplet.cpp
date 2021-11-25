// i<j<k  a[i] < a[j] > a[k]
#include <iostream>
#include <vector>
using namespace std;
void t_sum(int arr[],int n)  // O( n^2 )
{  int ans=0;
    for (int i = 1; i < n - 1; ++i) {
        int left=0,right=0;

        // find maximum value(less than arr[i])
        // from 0 to i-1
        for (int j = 0; j < i; ++j)
            if (arr[j] < arr[i])
                left++;

        // find maximum value(greater than arr[i])
        // from i+1 to n-1
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[i])
                right++;

        ans += left*right;
    }
    cout<<ans;

}

int triplet(int arr[],int i,int n,vector<int> store) // // O( 2^n )
{
    if(i==n+1)
     return 0;
    if(store.size()==3)
        {
            if(store[0]<store[1]&&store[1]>store[2])
            { //cout<<store[0]<<" "<<store[1]<<" "<<store[2]<<"\n";
                return 1;
            }
          else
           { // cout<<store[0]<<" "<<store[1]<<" "<<store[2]<<"\n";
              return 0;
           }

        }

        int k=0,j=0;

        k=triplet(arr,i+1,n,store);

        store.push_back(arr[i]);
         j=triplet(arr,i+1,n,store);
 return k+j;
}
void t_sum_n_cube(int arr[],int n)  // O( n^3 )
{
    int c=0;
    for(int i=0;i<n;i++)
    { for(int j=i+1;j<n;j++)
        { if(arr[i]<arr[j])
           { for(int k=j+1;k<n;k++)
            {  if(arr[j]>arr[k])
                    c++;

            }
           }
        }

    }
    cout<<c<<"\n";
}
int main()
{
    int n=6;

     int arr[]= { 2, 5, 3, 1, 4, 9 };

    t_sum(arr,n);
    cout<<"\n";
    t_sum_n_cube(arr,n);
    vector<int> store;
    cout<<triplet(arr,0,n,store);
}
