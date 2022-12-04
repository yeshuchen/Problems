#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		if(n & 1)
		{
			for(int i = 1; i <= n; i++)
				cout << 1 << ' ';
			cout << '\n';
			continue;
		}
		n /= 2;
		for(int i = 1; i < n; i++)
			cout << 1 << ' ' << 3 << ' ';
		if(n & 1) cout << 1 << ' ' << 3 << '\n';
		else cout << 2 << ' ' << 2 << '\n';
	}
	return 0;
}