//  set_union  &  set_intersection

#include <algorithm> // std::set_union , set_intersection ,  std::sort
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	vector<int> first{ 5, 10, 15, 20, 25 };
	vector<int> second{ 50, 40, 30, 20, 10 };


	// Print first array
	cout << "First array contains :";
	for (int i = 0; i < first.size(); i++)
		cout << " " << first[i];
	cout << "\n";

	// Print second array
	std::cout << "Second array contains :";
	for (int i = 0; i < second.size(); i++)
		cout << " " << second[i];
	cout << "\n\n";

	vector<int> v(1);        // initialize with one element
	vector<int> w(1);
	vector<int>::iterator it, st,inter;

    sort(first.begin(), first.end());
	sort(second.begin(), second.end());

	// Using default function
	it = set_union(first.begin(), first.end(), second.begin(),
						second.end(), v.begin());
    inter=set_intersection(first.begin(), first.end(), second.begin(),
						second.end(), w.begin());


	cout << "The union has " << (it - v.begin())
			<< " elements:\n";
	for (st = v.begin(); st != it; ++st)
		cout << ' ' << *st;
	cout << '\n';
	std::cout << "The intersection has " << (inter - w.begin()) << " elements:";
    for (it = w.begin(); it != inter; ++it)
        std::cout << ' ' << *it;
    std::cout << "\n";

	return 0;
}
