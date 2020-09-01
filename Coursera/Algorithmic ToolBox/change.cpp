#include <iostream>

int get_change(int m) {
 int i=0,j=0,k=0;
  while(m!=0)
  {
    if(m>=10)
   {
      i=m/10;
      m=m-i*10;
   }
  else if(m>=5)
  {j=m/5;
      m=m-j*5;
  }
  else{
    k=m;
      m=0;
    }
  }

  return i+j+k;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
