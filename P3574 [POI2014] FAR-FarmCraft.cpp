#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, tot;
int a[N], ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int f[N], sz[N], tmp[N];
inline bool cmp(int x, int y) {return sz[x] - f[x] < sz[y] - f[y];}
inline void dfs(int x, int fa)
{
	int res = 0;
	if(x != 1) f[x] = a[x];
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs(y, x);
	}
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		tmp[++res] = y;
	}
	sort(tmp + 1, tmp + res + 1, cmp);
	for(int i = 1; i <= res; i++)
	{
		f[x] = max(f[x], f[tmp[i]] + sz[x] + 1);
		sz[x] += sz[tmp[i]] + 2;
	}
}
signed main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	dfs(1, 0);
	cout << max(f[1], sz[1] + a[1]);
	return 0;
} 	