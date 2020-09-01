#include <iostream>
#include <vector>
#include<algorithm>
using std::vector;
class Segment{
public:
int starts,ends;
};
bool compare(Segment s1,Segment s2)
{
   if(s1.starts<s2.starts)
    { return 1;}
     else if(s1.starts==s2.starts)
      { if(s1.ends<s2.ends)
         { return 1; }
         else
            return 0;
      }
    else
        {return 0;}

}
int mod_binary_search(vector<Segment> arr,int p)
{
    int l=0,h=arr.size()-1,m;
    if(l<=h)
    {
        m=(l+h)/2;
        if(arr[m].ends)
    }
}
vector<int> fast_count_segments(vector<Segment> &a, vector<int> &points) {
  vector<int> cnt(points.size());

  sort(a.begin(),a.end(),compare);

int c=0;
  for (size_t i = 0; i < points.size(); i++) {
        cnt[i]=0;
    for (size_t j = 0; j < a.size(); j++) {
         if(a[j].starts <= points[i] && points[i] <= a[j].ends)
            {cnt[i]++ ;
            }
            c++;
            if(a[j].starts > points[i])
            {std::cout<<c<<
            " end";
                break;
            }

  }
  }
  return cnt;
}

vector<int> naive_count_segments(vector<Segment> a, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < a.size(); j++) {
      cnt[i] += a[j].starts <= points[i] && points[i] <= a[j].ends;
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<Segment> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i].starts >> a[i].ends;
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments

  vector<int> c = fast_count_segments(a, points);
  for (size_t i = 0; i < c.size(); i++) {
    std::cout << c[i] << ' ';
  }

}
