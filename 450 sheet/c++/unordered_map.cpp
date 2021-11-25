#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	// Declaration
	unordered_map<string,string> mymap;

	// Initialization
	mymap = {
            { "Australia", "Canberra"},
			{ "U.S.", "Washington" },
			{ "France", "Paris" } };

	// prints the bucket number of the beginning element
    cout<<"Bucket count"<<mymap.bucket_count()<<"\n";
	for(auto i:mymap)
    { cout<<i.first<<" "<<mymap.bucket(i.first)<<"\n"; }


    for (int i = 0; i <mymap.bucket_count() ; i++)  // Count no. of elements in each bucket using bucket_size(position)
        cout << "Bucket " << i << " has "<< mymap.bucket_size(i) << " elements.\n";


    // auto x=mymap.find("Australia");
    if(mymap.find("Australi")==mymap.end())           // if key not found then find() returns an end iterator
        cout<<"Not found \n";
    else
    { cout<<" Found "<<x->first<<"\n"; }
                               // working of find()     i guess :)
                               //  to check key i.e. not present
                               // if key generated is greater than bucket.size()
                               // if it is less then bucket.size() then its value == 0 ( not inserted)
                               // or it would have some inserted value

	return 0;
}
