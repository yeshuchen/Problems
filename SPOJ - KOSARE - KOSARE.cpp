#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m;
int b[1 << 20];
int f[1 << 20];
int cnt[1 << 20];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int k, x, res = 0;
		cin >> k;
		for(int i = 1; i <= k; i++)
		{
			cin >> x;
			res |= (1 << x - 1);
		}
		f[res]++;
	}
	b[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		b[i] = b[i - 1] * 2;
		if(b[i] >= mod) b[i] -= mod;
	}
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= (1 << m) - 1; j++)
			if(j & (1 << i - 1))
				f[j] += f[j ^ (1 << i - 1)];
	int ans = 0;
	for(int i = 0; i <= (1 << m) - 1; i++)
	{
		cnt[i] = cnt[i >> 1] + (i & 1);
		if(!(m - cnt[i] & 1)) ans = ans + b[f[i]] - 1;
		else ans = ans - b[f[i]] + 1;
		if(ans >= mod) ans -= mod;
		if(ans < 0) ans += mod;
	}
	cout << ans;
	return 0;
}