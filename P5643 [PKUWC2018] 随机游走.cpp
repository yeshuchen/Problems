#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353, N = 20;
int n, Q, rt;
vector<int> g[N];
int deg[N], A[N], B[N], f[1 << N];
int ksm(int a, int b)
{
	int base = 1;
	while(b)
	{
		if(b & 1) base = base * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return base;
}
void dfs(int x, int fa, int S)
{
	if(S & (1 << x - 1)) return;
	int resA = 0, resB = 0;
	int deg = g[x].size();
	for(int y : g[x])
	{
		if(y == fa) continue;
		dfs(y, x, S);
		resA = (resA + A[y]) % mod;
		resB = (resB + B[y]) % mod;
	}
	int inv = ksm(deg - resA, mod - 2);
	A[x] = inv; B[x] = (resB + deg) * inv % mod;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> Q >> rt; int m = (1 << n);
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 0; i < m; i++)
	{
		int flag = (__builtin_popcount(i) & 1) ? 1 : -1;
		for(int j = 1; j <= n; j++) A[j] = B[j] = 0;
		dfs(rt, 0, i); f[i] = (flag * B[rt] + mod) % mod;
	}
	for(int o = 2, k = 1; o <= m; o <<= 1, k <<= 1)	
		for(int i = 0; i < m; i += o)
			for(int j = 0; j < k; j++)
				f[i + j + k] = (f[i + j + k] + f[i + j]) % mod;
	while(Q--)
	{
		int k, S = 0;
		cin >> k;
		for(int i = 1, x; i <= k; i++) cin >> x, S |= (1 << x - 1);
		cout << f[S] << '\n';
	}
	return 0;
}