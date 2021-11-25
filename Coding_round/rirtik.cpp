#include <bits/stdc++.h>
using namespace std;
 bool isValid(string str) {

        if (str.size() == 0) {
            return true;
        }
        int count = 0;
        int i = 0;
        while (i < str.size()) {

            if (str[i] == '(') {
                count++;
            } else if (str[i] == ')') {
                if (count == 0)
                    return false;
                else
                    count--;
            }
            i++;
        }

        if(count != 0)
            return false;

        return true;
    }
    // Driver code
int main()
{
	string str;
	cin>>str;

	// Function call
	if (isValid(str))
		cout << "Balanced";
	else
		cout << "Not Balanced";
	return 0;
}
