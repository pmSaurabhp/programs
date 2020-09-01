#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  if(n==2)
    {summands.push_back(n);
        return summands;
    }
    else{
        n=n-1;
     summands.push_back(1);
     for(int i=2;i<=n;i++)
  {
      if(n/i>1){
            if(n/i==2)
            {   if(n%i!=0)
                {n=n-i;
                  summands.push_back(i);
                }
                else{summands.push_back(n);
                break;
                }
            }
            else{n=n-i;
                  summands.push_back(i);
                }

         }
      else{
        summands.push_back(n);
        break;
    }
  }
    }


  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
    int sum=0;
    for (size_t i = 0; i < summands.size(); ++i) {
    sum=sum+summands[i];
  }
  if(sum==n){
    std::cout<<"Equal";
  }
  else{
    std::cout<<"False";
  }
}
