#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int i=0,n=stops.size(),c=0,last,visited=-1,covered=0;
    n=n+1;
    while(i<n)
    {   if(i==n-1)
        {
            covered=stops[i];
            return c;
        }
        else if(tank>=(stops[i]-covered))
        {   last=i;
            i++;
        }
        else{
            if(last==visited)
            {
                return -1;
            }
            i=last;
            visited=i;
            c++;
            covered=stops[i];
        }


    }

    cout<<c<<" i = "<<i;

}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+1);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);
    stops[n]=d;

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
