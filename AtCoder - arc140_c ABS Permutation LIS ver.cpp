#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, x;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> x;
	cout << x << ' ';
	if(n % 2)
	{
		if(x == n / 2 + 1)
		{
			for(int i = x - 1; i; i--)
				cout << i << ' ' << x * 2 - i << ' ';
		}
		else if(x < n / 2 + 1)
		{
			int t = x;
			x = n / 2 + 1; cout << x << ' ';
			for(int i = x + 1; i < n; i++)
				cout << i << ' ' << (2 * x - i <= t ? 2 * x - i - 1 : 2 * x - i) << ' ';
			cout << n;
		}
		else
		{
			int t = x;
			x = n / 2 + 1; cout << x << ' ';
			for(int i = x - 1; i > 1; i--)
				cout << i << ' ' << (2 * x - i >= t ? 2 * x - i + 1 : 2 * x - i) << ' ';
			cout << 1;
		}
	}
	else
	{
		if(x == n / 2)
		{
			for(int i = x + 1; i < n; i++)
				cout << i << ' ' << n - i << ' ';
			cout << n;
		}
		if(x == n / 2 + 1)
		{
			for(int i = x - 1; i > 1; i--)
				cout << i << ' ' << n + 2 - i << ' ';
			cout << 1;
		}
		if(x < n / 2)
		{
			int t = x;
			x = n / 2 + 1;
			for(int i = x; i < n; i++)
				cout << i << ' ' << (n + 1 - i <= t ? n - i : n + 1 - i) << ' ';
			cout << n;
		}
		if(x > n / 2 + 1)
		{
			int t = x;
			x = n / 2;
			for(int i = x; i > 1; i--)
				cout << i << ' ' << (n + 1 - i >= t ? n + 2 - i : n + 1 - i) << ' ';
			cout << 1;
		}
	}
	return 0;
}