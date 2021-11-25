#include <iostream>
#include <vector>

using namespace std;
int main()
{                                   // also see level order traversal

    int r=4,c=5;                                // vector<int> mat(r,0)   1D vector with known length & initialized with 0
    vector<vector<int> > mat( r , vector<int> (c, 3));   // 2D matrix with known rows and column and initial value 3
                                                    // vector<vector<int> > mat(r)    2D matrix with known no. of rows
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
           // mat[i][j]=5;
             mat[i].push_back(5);
        }

    }
    vector<int> t={1,2,3};
    mat.push_back(t);


    for(int i=0;i<mat.size();i++)
    {  for(int j=0;j<mat[i].size();j++)
        {
          cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }

    vector<int> temp={1,3,2,7,4,6};

    for(int i=0;i<temp.size();i++)    // delete 1 element
    {
        if(temp[i]==4)
        {
            temp.erase(temp.begin()+i);
        }
    }
     for(int i=0;i<temp.size();i++)
     {
         cout<<temp[i]<<" ";
     }

    cout<<"\n";
    temp.erase(temp.begin()+1,temp.begin()+3);   // delete a range of elements

//     for(int i=0;i<temp.size();i++)      // print using index
//     {
//         cout<<temp[i]<<" ";
//     }

    vector<int>:: iterator ptr;                    // print using iterator
    for(ptr=temp.begin();ptr!=temp.end();ptr++)
        cout<<*ptr<<" ";


                                        // also see set1
                                        // sets can be  printed using iterator only
}
