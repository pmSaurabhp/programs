#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {  // fails at n=20 -> 1 2 4 5 10 20
  std::vector<int> sequence;                    // correct 1 3 9 10 20
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}
void iterative_optimal_sequence(int n)
{ int operation[3]={1,2,3};
  std::vector<int> prev;
  int t[n+1];
  for(int i=0;i<n+1;i++)
   { t[i]=0; }
 prev.push_back(0);
 prev.push_back(1);
   for(int i=2;i<=n;i++)
  { int x;
       for(int j=0;j<3;j++)
    {
      if(j>0)
      { if(i%operation[j]==0)
         {
           if(t[i]==0)
           {
               t[i]=t[i/operation[j]]+1;
                 x=i/operation[j];


           }
           if(t[i]>t[i/operation[j]]+1)
            { t[i]=t[i/operation[j]]+1;
              x=i/operation[j];

            }
         }

      }
      if(j==0)
      { if(i>operation[j])
         {
           if(t[i]==0)
           {
               t[i]=t[i-operation[j]]+1;
                 x=i-operation[j];


           }
           if(t[i]>t[i-operation[j]]+1)
            { t[i]=t[i-operation[j]]+1;
            x=i-operation[j];


            }
         }

      }

    }
     prev.push_back(x);


  }

   std::cout<<t[n]<<"\n";


std::vector<size_t> sequence;
sequence.push_back(n);
 while(n!=1)
 {
     sequence.push_back(prev[n]);
     n=prev[n];
 }
 reverse(sequence.begin(),sequence.end());
 for(size_t i=0;i<sequence.size();i++)
 {
     std::cout<<sequence[i]<<" ";
 }
}
int main() {
  int n;
  std::cin >> n;
  //vector<int> sequence = optimal_sequence(n);
  //std::cout << sequence.size() - 1 << std::endl;
  //for (size_t i = 0; i < sequence.size(); ++i) {
    //std::cout << sequence[i] << " ";
  //}

 iterative_optimal_sequence(n);
}
