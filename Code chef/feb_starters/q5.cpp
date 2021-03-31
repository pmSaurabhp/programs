#include <bits/stdc++.h>

using namespace std;

class college
{
    public:
    int id;
    int rank;
};
class student
{
    public :
    int id;
    int rank;
    vector<college> list;
};

bool compare_std(student s1,student s2)
{
    return s1.rank<s2.rank;
}
bool compare_clg(college c1,college c2)
{
    return c1.rank<c2.rank;
}
int main() {
    ios_base::sync_with_stdio(false);   // fast input output
    cin.tie(NULL);                      // fast input output
int t;
  cin>>t;

 while(t--)
 {  int n,m;
    cin>>n>>m;
    college clg[n];

    student std[m];
    for(int i=0;i<n;i++)
       {  clg[i].id=i+1;
          cin>>clg[i].rank;
       }
    for(int i=0;i<m;i++)
       { std[i].id=i+1;
         cin>>std[i].rank;
       }
     for(int i=0;i<m;i++)
       { int k;
         cin>>k;
        for(int j=0;j<k;j++)
        { college t;
            cin>>t.id;
            t.rank=clg[t.id-1].rank;
           std[i].list.push_back(t);
        }
       }

       sort(std,std+m,compare_std);

      for(int i=0;i<m;i++)
      {
          sort(std[i].list.begin(),std[i].list.end(),compare_clg);
      }


       for(int i=0;i<m;i++)
    { int f=0;
        for(int j=0;j<std[i].list.size();j++)
        { if(clg[std[i].list[j].id-1].rank!=0)
            { if(std[i].id==1)
                { cout<<std[i].list[j].id<<"\n";
                 f=1;
                }
              clg[std[i].list[j].id-1].rank=0;
                break;
            }

        }
        if(std[i].id==1 && f==0)
             cout<<"0\n";
        if(std[i].id==1)
            break;

    }
    //for(int i=0;i<m;i++)
   // {
 //       for(int j=0;j<std[i].list.size();j++)
 //       {
  //          cout<<std[i].list[j].id<<" ";
  //      }
//        cout<<"\n";
   // }

 }
	return 0;
}
