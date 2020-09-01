#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include<algorithm>
using namespace std;

class Segment {
  public:
  int start, end;
};
bool compare(Segment s1,Segment s2)
{
    if(s1.start<s2.start)
    { return 1;}
    else if(s1.start==s2.start)
      { if(s1.end<=s2.end)
         { return 1; }
         else
            return 0;
      }
    else
        return 0;
}

void optimal_points(vector<Segment> &segments) {
  vector<int> points;
sort(segments.begin(),segments.end(),compare);
size_t t=0;
  for (size_t i = 0; i < segments.size(); ++i) {
        size_t a=0,b=0,ss=segments[i].start,se=segments[i].end;
    for(size_t j = ss; j <= se; ++j)
    {  size_t c=0;
        for (size_t k = i; k < segments.size(); ++k)
       {
        if(j>=segments[k].start&&j<=segments[k].end){
            c++;

            if(k==segments.size()-1)
            {
              i=k;
              continue;
            }
        }
        else if(j==segments[i].end){
                i=k-1;
                break;
            }
        else{
            continue;}
       }
       if(b<c){
            b=c;
            a=j;
        }
    }
    if(t!=a)
      { points.push_back(a);
      t=a;
      }
  }

   cout<<points.size()<<"\n";

for(size_t j =0; j <points.size(); ++j)
   {
          cout<<points[j]<<" ";
   }
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }

  optimal_points(segments);
return 0;
}
