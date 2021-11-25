// 4aaaa2bb    o/p TRUE
// 4aaaa3bb    o/p FALSE

#include<iostream>
#include <string>
using namespace std;

int change(string str)
{
	int num = 0;
	int x;
	for(int i=0; i<str.length();i++) {
		 x = str[i] - '0';
		num = num*10 + x;
	}

	return num;
}

int main() {
	string s;
	cin>>s;
	int n = s.length();
	int i;
    int f=0;
	for(i=0; i<n; i++) {
		string str = "";
		int count = 0;
		// cout<<s[i]<<" ";
		while(s[i] >= '0' and s[i] <= '9')
		{
			str += s[i];
			i++;
		}

		int x = change(str);

		while(s[i] > '9' && i<n )
		{
			count++;
			i++;
		}
        // cout<<count<<" "<<x<<" ";
		if(count != x)
		{  f=1;
			break;
		}
		i--;   // this mistake came to light when     i did DRY run after implementing or add print statements
}

	if(f == 0) {
		cout<<"True";
	}
	else {
		cout<<"False";
	}

	return 0;
}
