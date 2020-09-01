#include <iostream>
#include <vector>
#include<sstream>
using namespace std;
void change(int array[]) // pass by reference
{
    array[1]=100;
}
void change_vector(vector<int> &vect)   // its pass by reference
{                               // void change(vector<int> vect)   pass by value
    vect[1]=200;
}

int main() {
int array[3];
vector<int> vect(3);
cout<<"Enter Array";
for(int i=0;i<3;i++)
{
    std::cin>>array[i];
}
cout<<"Enter Vector";
for(int i=0;i<3;i++)
{
    std::cin>>vect[i];
}


change(array);
change_vector(vect);
for(int i=0;i<3;i++)
{
    std::cout<<array[i]<<" ";
}
cout<<"\n";
for(int i=0;i<3;i++)
{
    std::cout<<vect[i]<<" ";
}
}
