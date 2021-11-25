int maxSubarraySum(int arr[], int n){
     int l=-1,h=-1,l_can=-1,h_can=-1;
     int max_sum=0,candidate_max=0;
    for(int i=0;i<n;i++)
    { candidate_max += arr[i];
     if(candidate_max<=0)
       candidate_max = 0;
     else
     {
        if(candidate_max == arr[i])
        { l_can=i;
          h_can = i;
        }
        else
          h_can++;

        if(max_sum < candidate_max)
        { max_sum = candidate_max;
             l=l_can;
             h=h_can;
        }
     }
    }
     for(int i=l;i<h+1;i++)
        cout<<arr[i]<<" ";
    return max_sum;
}

