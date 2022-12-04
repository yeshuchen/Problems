#include<bits/stdc++.h>
using namespace std;
int T, n, m, k;
int a[1000005], c[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> m >> k;
		for(int i = 1; i <= k; i++)
			cin >> a[i];
		long long ans = 0;
		bool f1 = 0;
		for(int i = 1; i <= k; i++)
		{
			c[i] = a[i] / n;
			if(c[i] >= 2) ans += c[i];
			if(c[i] > 2) f1 = 1;
		}
		if(ans >= m && (f1 || m % 2 == 0)) {cout << "Yes\n"; continue;}
		ans = f1 = 0;
		for(int i = 1; i <= k; i++)
		{
			c[i] = a[i] / m;
			if(c[i] >= 2) ans += c[i];
			if(c[i] > 2) f1 = 1;
		}
		if(ans >= n && (f1 || n % 2 == 0)) {cout << "Yes\n"; continue;}
		cout << "No\n";
	}
	return 0;
}