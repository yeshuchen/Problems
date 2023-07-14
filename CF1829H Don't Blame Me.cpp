#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int T, n, k;
int a[200005];
long long f[200005][100];
int main()
{
	cin >> T;
	while(T--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < 64; j++)
				f[i][j] = 0;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j < 64; j++)
				f[i][j] = (f[i][j] + f[i - 1][j]) % mod,
				f[i][j & a[i]] = (f[i][j & a[i]] + f[i - 1][j]) % mod;
			f[i][a[i]] += 1;
		}
		long long ans = 0;
		for(int i = 0; i < 64; i++)
		{
			int cnt = 0;
			for(int j = 0; j < 6; j++)
				if(i & (1 << j))
					cnt++;
			if(cnt == k) ans = (ans + f[n][i]) % mod;
		}
		cout << ans << '\n';
	}
	return 0;
}