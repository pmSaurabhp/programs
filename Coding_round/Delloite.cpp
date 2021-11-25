// run this in codechef editor
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string str="i.like.this.program.very.much";

  vector<string> stored;
  int j=0;
  string temp;
  for(int i=0;i<str.size();i++)
  {
      temp.push_back(str[i]);

    if(str[i]=='.' || i==str.size()-1)
    {
       stored.push_back(temp);

      if(j==0)
      { int n=stored[0].size();
         n=n-1;

        stored[0].erase(stored[0].begin()+n);
         // cout<<n<<" "<<stored[0]<<"\n";
      }

      if( i==str.size()-1)
        {//  string t=stored[j];
        //     stored.erase(stored.begin()+j);
        //     t=t+'.';
         //cout<<stored[j]<<"\n";
          stored[j]=stored[j]+".";
        }
        temp.erase();
    j++;                         // i placed it in top this was wrong
    }
  }

  for(int i=stored.size()-1;i>=0;i--)
  {  cout<<stored[i];
  }
	return 0;
}
