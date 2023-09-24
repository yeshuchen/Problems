#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
bool _n[N], _m[N], _k[N];
int T, n, m, k, mod;
int f[62][2][2][2], g[62][2][2][2];
inline void dfs(int pos, bool ln, bool lm, bool lk)
{
	if(g[pos][ln][lm][lk]) return;
	if(!pos)
	{
		f[pos][ln][lm][lk] = 0;
		g[pos][ln][lm][lk] = 1;
		return;
	}
	int upn = ln ? _n[pos] : 1, upm = lm ? _m[pos] : 1;
	for(int i = 0; i <= upn; i++)
		for(int j = 0; j <= upm; j++)
		{
			if(lk && (i ^ j) < _k[pos]) continue;
			dfs(pos - 1, ln && i == upn, lm && j == upm, lk && (i ^ j) == _k[pos]);
			int ret1 = g[pos - 1][ln && i == upn][lm && j == upm][lk && (i ^ j) == _k[pos]], ret2 = f[pos - 1][ln && i == upn][lm && j == upm][lk && (i ^ j) == _k[pos]];
			f[pos][ln][lm][lk] = (f[pos][ln][lm][lk] + (1ll * (i ^ j) << pos - 1) % mod * ret1 % mod + ret2) % mod;
			g[pos][ln][lm][lk] = (g[pos][ln][lm][lk] + ret1) % mod;
		}
}
signed main()
{
	cin >> T;
	while(T--)
	{
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		memset(_k, 0, sizeof _k);
		memset(_m, 0, sizeof _m);
		memset(_n, 0, sizeof _n);
		cin >> n >> m >> k >> mod; n--; m--;
		for(int i = 60; i; i--)
		{
			_n[i] = n & (1ll << i - 1);
			_m[i] = m & (1ll << i - 1);
			_k[i] = k & (1ll << i - 1);
		}
		dfs(60, 1, 1, 1);
		cout << (f[60][1][1][1] - k % mod * g[60][1][1][1] % mod + mod) % mod << '\n';
	}
	return 0;
}