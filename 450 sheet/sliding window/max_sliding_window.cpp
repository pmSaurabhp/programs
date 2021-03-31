// time complexity = n + f(n) = O(n)
// worst case 3 1 2 3 1 2 3 1 2 3 1 2 3  and w=4
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void max_sliding_window(vector<int> const & A, int w)
{  int i,j,n;
    deque<int> q;
    vector<int> res;

    i=0; j=0; n=A.size();


    while(j<n)
    {  if(q.empty()) q.push_back(A[j]);

       else if(q[0]>=A[j])
      {  while(q.size()&&q.back()<A[j])
            {  q.pop_back();  }

          q.push_back(A[j]);
      }
       else{
        deque<int> emt;
        swap(q,emt);
        q.push_back(A[j]);
       }
     if(j-i<w-1)
       { j++;  }
     else{
        res.push_back(q.front());
        if(A[i]==q.front()) q.pop_front();  // max out of window

        i++; j++;
       }


    }
    for(int k=0;k<res.size();k++)
    {
        cout<<res[k]<<" ";
    }

}
void max_sliding_window_naive(vector<int> const & A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A, w);

    return 0;
}
