#include<bits/stdc++.h>
const int mod = 1e8;
using namespace std;
char s[5005], t[5005];
int c[5005][5005], f[5005], g[5005], h[5005], ans[5005];
void add(int id, int x, int v)
{
	if(!x) c[id][x] += v, x = 1;
	for(int i = x; i <= 5000; i += (i & -i))
	{
		c[id][i] += v;
		c[id][i] -= (c[id][i] >= mod ? mod : 0);
	}
}
int ask(int id, int x)
{
	int res = 0;
	for(int i = x; i; i -= (i & -i))
	{
		res += c[id][i];
		res -= (res >= mod ? mod : 0);
	}	
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s + 1 >> t + 1;
	int n = strlen(s + 1) - 1, m = strlen(t + 1) - 1;
	add(1, 1, 1);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(s[i] == t[j])
			{
				f[j] = h[j - 1] + 1;
				g[j] = ask(f[j], j);
				ans[f[j]] += g[j];
				ans[f[j]] %= mod;
			}
			f[j] = max({f[j], f[j - 1], h[j]});
		}
		for(int j = 1; j <= m; j++)
		{
			h[j] = f[j]; f[j] = 0;
			if(s[i] == t[j])
				add(h[j] + 1, j + 1, g[j]);
		}
	}
	cout << h[m] << '\n' << ans[h[m]];
	return 0;
}