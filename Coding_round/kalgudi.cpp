int maxSubarraySum_naive(int arr[], int n){

    int m=0;
    for(int i=0;i<n;i++)
    { int mt=arr[i];
        m=max(m,mt);
        for(int j=i+1;j<n;j++)
        {  mt += arr[j];

             m=max(m,mt);

        }

    }
    return m;

}
int maxSubarraySum(int arr[], int n){

     int max_=0,sum=0;
    for(int i=0;i<n;i++)
    { sum += arr[i];
     if(sum<=0)
      sum = 0;
     else
     {
         max_ = max(max_ , sum);


     }
    }
    return max_;
}
