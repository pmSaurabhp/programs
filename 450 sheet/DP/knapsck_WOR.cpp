#include <iostream>
#include <vector>
using namespace std;

int KWOR(int wk,int n,int v[],int w[])   // this recursion method is used for
{                                        //  dp solution
    if(n==0||wk==0)
        return 0;
    int k1=0,k2=0;

//    if(n==1)
//        cout<<wk<<"\n";

          k1=KWOR(wk,n-1,v,w);  // exclusive

          if(wk>=w[n-1])
            k2=v[n-1]+KWOR(wk-w[n-1],n-1,v,w);  //inclusive

    return max(k1,k2);
}
int KWOR_2(int wk,vector<int> v,vector<int> w)  // my recursive solution
{
    if(w.size()==0||wk==0)
        return 0;
    int sum=0;
    for(int i=0;i<w.size();i++)
    {
        vector<int> tv=v;
        vector<int> tw=w;
        if(wk>=tw[i])
        {
            tw.erase(tw.begin()+i);
            tv.erase(tv.begin()+i);

            sum=max(sum,v[i]+KWOR_2(wk-w[i],tv,tw));
        }
    }
    return sum;

}
int main()
{
    int wk=10;
    int v[]={3,14,26,9,4,20,7};
    int w[]={6,3,4,2,5,7,8};

    cout<<KWOR(wk,4,v,w)<<"\n";

     vector<int> v2={3,14,26,9,4,20,7};
    vector<int> w2={6,3,4,2,5,7,8};

    cout<<KWOR_2(wk,v2,w2);
}
