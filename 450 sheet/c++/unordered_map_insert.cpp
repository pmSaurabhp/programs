// C++ program to illustrate
// unordered_map::insert({key, element})

#include <bits/stdc++.h>
using namespace std;

int main()
{
	unordered_map<int, int> ump;

	// insert elements in random order
	ump.insert({ 20, 130 });
	ump.insert({ 100, 410 });
	ump.insert({ 31, 60 });

  cout<<ump[10]<<"\n";    //  10 and 25 also get inserted in ump
  ump[25]=400;
                              // to find an element use if(ump.find(20)==ump.end() ) ;
  if(ump.find(15)==ump.end()) // donot use if(ump[15] == 0) it will insert 15 int hash map
        cout<<"not found \n";
  else
        cout<<"Found\n";

	cout << "KEY\tELEMENT\n";

	for (auto itr = ump.begin(); itr != ump.end(); itr++) {
		cout << itr->first
			<< '\t' << itr->second << '\n';
	}
	return 0;
}
