#include <iostream>
#include <vector>
#include<string>
#include<sstream>

using namespace std;
int main() {
string colour;
std::cin>>colour;
// method 1
int b;
b=int(colour[1])-int('0');  // int(colour[1])-48
std::cout<<b<<"\n";

// method 2
std::stringstream ret;
ret<<colour[1];
int a;
ret>>a;
std::cout<<a;

}
