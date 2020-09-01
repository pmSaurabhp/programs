#include <iostream>
#include <algorithm>



int main() {
     int64_t n;
    int64_t a,b; // int a,b; does not work
    a=100000;
    b=900000;
    n=a*b;   // n=100000*900000; does not work
    std::cout<<n;
    return 0;
}
