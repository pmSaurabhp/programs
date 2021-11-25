#include <iostream>
#include<string>
using namespace std;

int change(string str)
{
	int num = 0;
	for(int i=0; i<str.length(); i++) {
		int x = str[i] - '0';
		num = num*10 + x;
	}

	return num;
}

int main() {
	string s;
	cin>>s;
	int n = s.length();
	int i;

	for(i=0; i<n; i++) {
		string str = "";
		int count = 0;
		while(s[i] >= '0' and s[i] <= '9')
		{
			str += s[i];
			i++;
		}

		int x = change(str);

		while(s[i]>'9')
		{
			count++;
			i++;
		}
		i--;

		if(count != x)
		{
			break;
		}
	}

	if(i == n) {
		cout<<"True";
	}
	else {
		cout<<"False";
	}

	return 0;
}
