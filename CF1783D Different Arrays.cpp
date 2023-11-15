#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 305 * 305 * 2, del = 300 * 300, mod = 998244353;
int n;
int a[N], f[N], g[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	g[a[2] + del] = 1;
	for(int i = 3; i <= n; i++)
	{
		memset(f, 0, sizeof(f));
		for(int j = 0; j <= 2 * del; j++)
		{
			int x = j - del;
			if(x == a[i]) f[j] += g[del];
			else
			{
				if(x - a[i] + del >= 0) f[j] += g[x - a[i] + del];
				if(a[i] - x <= del) f[j] += g[a[i] - x + del];
			}
			f[j] %= mod;
		}
		memcpy(g, f, sizeof(g));
	}
	int ans = 0;
	for(int i = 0; i <= 2 * del; i++) ans += g[i], ans %= mod;
	cout << ans;
	return 0;
}