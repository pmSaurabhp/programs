#include<bits/stdc++.h>
using namespace std;

int main() {

	int n, num1, num2, x, digit, rev1, rev2, sum, ans;
	cin>>n;

	while(n>1)
	{
		for(int i=(n-1); i>0; i--)
		{
			 rev1 = 0;
			 num1 = i;
			 x = num1;

			while(x != 0)
			{
				digit = x % 10;
         		rev1 = (rev1 * 10) + digit;
         		x = x / 10;
			}

			if(num1 == rev1)
			{
				break;
			}
		}

		for(int i=(n+1); i<INT_MAX; i++)
		{
			 rev2 = 0;
			 num2 = i;
			 x = num2;

			while(x != 0)
			{
				digit = x % 10;
         		rev2 = (rev2 * 10) + digit;
         		x = x / 10;
			}

			if(num2 == rev2)
			{
				break;
			}
		}

		sum = rev1 + rev2;
		int y = sum;
		ans = 0;
		while(y != 0)
		{
			digit = y%10;
			ans = (ans*10) + digit;
			y = y / 10;
		}

		if(ans == sum)
		{
			cout<<sum;
			break;
		}
		else
		{
			n--;
		}
	}

}
