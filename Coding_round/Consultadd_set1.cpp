// count adjacent similar no. , print count then element
// 112331
// n = 1    // no. of phases
// 21 12 23 11
// count then element
#include <bits/stdc++.h>
using namespace std;

string ans(string s) {

	int count = 1;
	string str = "";
	for(int i=0; i<s.length(); i++) {
		while(s[i] == s[i+1])
		{
			count++;
			i++;
		}
		char x =  count + '0';

		 str = str + x + s[i];
		//str = str + (char)count + s[i];       // wrong as (char) casting changes no. -> its ascii equivalent character

		count = 1;
	}

	return str;
}
int main() {

	string s;
	cin>>s;
	int n;
	cin>>n;

	for(int i=0; i<n; i++) {
		s = ans(s);
	}
	cout<<s;


}
