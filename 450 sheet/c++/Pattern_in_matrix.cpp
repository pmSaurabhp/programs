// https://www.interviewbit.com/problems/prettyprint/

// solution from discussion  n^2
vector<vector<int> > Solution::prettyPrint(int n) {
   vector<vector<int> > ans;
    for(int i=1;i<(2*n);i++)
    {
        vector<int> a;
        for(int j=1;j<(2*n);j++)
        {
            a.push_back(  max( abs(i-n), abs(j-n) ) + 1 );
        }
        ans.push_back(a);
    }
    return ans;
}


// my solution  n^3
vector<vector<int> > Solution::prettyPrint(int A) {
    int r=2*A-1;
    vector<vector<int> > mat( r , vector<int> (r, A));   // 2D matrix with known rows and column and initial value A
                                    // vector<vector<int> > mat(r)    2D matrix ith known no. of rows
                                    // vector<int> mat(r,0)   1D vector with known lengt & initialized with 0
    for(int i=1;i<r;i++)
    {
        for(int j=i;j<r-i;j++)
        {
           for(int k=i;k<r-i;k++)
           { mat[j][k]=A-i;
           }

        }

    }
    return mat;
}
