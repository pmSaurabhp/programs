#include<iostream>
#include<vector>
using namespace std;

   void f(int startIdx, int n, int k, vector<int> &currSet, vector<vector<int>>&res) {
        // Base case
        // Positive base case
        if(k == 0){

            for(int i = 0; i < currSet.size()-1; i++) {
                if(2*currSet[i] > currSet[i+1]) return;
            }

            res.push_back(currSet);
            return;
        }

        // Empty suffix array
        // k is non-zero
        if(startIdx > n)
            return;

        // Pruning step
        if(n-startIdx+1 < k)
            return;


        // Recursive step
        // Exclude
        f(startIdx+1, n, k, currSet, res);

        // Include
        // Push down the contribution
        currSet.push_back(startIdx);
        f(startIdx+1, n, k-1, currSet, res);
        currSet.pop_back();
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> currSet;
        vector<vector<int>> res;

        f(1, n, k, currSet, res);
    for(int i = 0; i < res.size(); i++)
    {
    for(int j=0;j<res[i].size();j++)
    {
        cout<<res[i][j]<<" ";
    }
    cout<<"\n";
    }

    }
int main()
{ int n,k;
    cin>>n>>k;
    combine(n,k);
}
