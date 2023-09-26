#include<bits/stdc++.h>
#define int long long
using namespace std;
int T, n;
signed main()
{
	cin >> T;
	while(T--)
	{
		cin >> n;
		int mn1 = INT_MAX, mn2 = INT_MAX;
		long long suma = 0, sumb = 0;
		for(int i = 1, x; i <= n; i++)
		{
			cin >> x;
			mn1 = min(mn1, x);
			suma += x;
		}
		for(int i = 1, x; i <= n; i++)
		{
			cin >> x;
			mn2 = min(mn2, x);
			sumb += x;
		}
		cout << min(suma + n * mn2, sumb + n * mn1) << '\n';
	}
	return 0;
}