#include <iostream>
using namespace std;

int main() {
	int t;
  cin>>t;

 while(t--)
 {  int n=7,m;


    int c=0;
    for(m=1;m<30;m++)
    { cout<<n<<" "<<m<<"\n";
          for(int i=1;i<=n;i++)
    { for(int j=i+1;j<=n;j++)
        { if((m%i)%j==(m%j)%i)
           { cout<<i<<" "<<j<<"  ";
             c++;

           }
        }

    }
  cout<<"c : "<<c<<"\n";
 c=0;

    }

 }
	return 0;
}
