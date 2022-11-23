#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int a[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		memset(a, 0, sizeof(a));
		int n, k, b, s;
		cin >> n >> k >> b >> s;
		if(s / k < b || n * (k - 1) + b * k < s) {cout << -1 << '\n'; continue;}
		a[n] = b * k + k - 1;
		if(a[n] > s)
		{
			a[n] = s;
			for(int i = 1; i <= n; i++)
				cout << a[i] << ' ';
			cout << '\n';
			continue;
		}
		s -= a[n];
		for(int i = n - 1; i >= 1; i--)
		{
			if(s < k - 1) {a[i] = s; break;} 
			else a[i] = k - 1, s = s - (k - 1);
		}
		for(int i = 1; i <= n; i++) cout << a[i] << ' ';
		cout << '\n';
	}
	return 0;
}