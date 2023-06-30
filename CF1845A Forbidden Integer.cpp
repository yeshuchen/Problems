#include<bits/stdc++.h>
using namespace std;
int T, n, m, k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> m >> k;
		if(k != 1)
		{
			cout << "YES\n" << n << '\n';
			for(int i = 1; i <= n; i++)
				cout << 1 << ' ';
			cout << '\n';
			continue;
		}
		if(n == 1 || m == 2 && n % 2 != 0 || m == 1) {cout << "NO\n"; continue;}
		cout << "YES\n";
		cout << n / 2 << '\n';
		while(n > 3) cout << 2 << ' ', n -= 2;
		cout << n << '\n';
	}
	return 0;
}