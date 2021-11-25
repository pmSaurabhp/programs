#include <iostream>
#include <vector>
using namespace std;

vector<int> M_merge(vector<int> arr_l,vector<int> arr_r)
{
    int i=0,j=0;
    vector<int> res;

    while(i<arr_l.size() && j< arr_r.size())
    {
        if(arr_l[i]<=arr_r[j] )
        {   res.push_back(arr_l[i]);
            i++;
        }
        else if(arr_l[i]>arr_r[j] ){
            res.push_back(arr_r[j]);
            j++;
        }
    }

     while(i<arr_l.size() )
        { res.push_back(arr_l[i]);
            i++;
        }


     while(j<arr_r.size() )
        {  res.push_back(arr_r[j]);
            j++;
        }

    return res;
}

vector<int> M_sort(vector<int> &arr,int l,int h)
{
    if(l==h)
    {  vector<int> res(1);
        res[0]=arr[l];
      return res;
    }
    if(l<h)
    { int m=(l+h)/2;

        vector<int> arr_l=M_sort(arr,l,m);
        vector<int> arr_r=M_sort(arr,m+1,h);

        vector<int> res=M_merge(arr_l,arr_r);

        return res;
    }

}
int main()
{   int n=9;
    vector<int> arr={5,2,7,4,1,3,6,9,8};


    vector<int> res=M_sort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<res[i]<<" ";
    }
}
