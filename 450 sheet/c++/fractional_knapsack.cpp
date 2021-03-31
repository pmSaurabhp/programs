#include <iostream>
#include<algorithm> // for sort()
using namespace std;
class Item
{
public:

    int weights,values;
};

bool compare_fun(Item i1,Item i2)
{
    double a1,a2;
    a1=(double)i1.values/i1.weights;
    a2=(double)i2.values/i2.weights;
    return (a1>a2);
}
double get_optimal_value(int capacity,int n,Item b[]) {
  double value = 0.0;



    sort(b,b+n,compare_fun);


    int i=0;
    while(capacity!=0&&i<n)
    {
        if(capacity>=b[i].weights)
        {
            capacity=capacity-b[i].weights;
            value=value+b[i].values;
            i++;
        }
        else {
            value=value+((double)b[i].values/b[i].weights)*capacity;
            capacity=0;
        }

    }
  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
Item arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i].values >> arr[i].weights;
  }

 double optimal_value = get_optimal_value(capacity,n,arr);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
