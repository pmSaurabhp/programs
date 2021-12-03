#include <iostream>
#include <vector>
                        // star   arr[10^9] gives error   size should be less than 10^9   size < 10^9  same for vector
using namespace std;
void fun(int arr[]) // pass by reference
{                   // pass by value is not possible in array use vectors for pass by value
    arr[1]=100;
}
void fun_vector(vector<int> &vect)   // its pass by reference
{                               // void change(vector<int> vect)   pass by value
    vect[1]=200;
}
int main()
{
   // int  brr[1000000000];   gives error
  int arr[3];                 //   [ ]
  vector<int> vect(3);        //   ( )  vector is implementation of Dynamic array
                              //  vector<int> vect{ 1 , 2 ,3}  vector gets initialized by zero
cout<<"Enter Array";          //  vector<int> vect(3,-1); vector gets initialized by -1 and has size 3
for(int i=0;i<3;i++)
{
    std::cin>>arr[i];
}

cout<<"Enter Vector 2 elements ";
for(int i=0;i<2;i++)           // vector<int> vect;   when size is unknown
{                              // vect.push_back(20);
    std::cin>>vect[i];
}

vect.push_back(20);          //   vect = { _ , _ , _ , 20 }

fun(arr);
fun_vector(vect);

for(int i=0;i<3;i++)
{
    std::cout<<arr[i]<<" ";
}
cout<<"\n";
for(int i=0;i<4;i++)
{
    std::cout<<vect[i]<<" ";
}
}
