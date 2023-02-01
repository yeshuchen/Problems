#include<bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5;
int n, m, tot;
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int dp[N], f[N], ans;
inline void dfs(int x, int fa)
{
	int max1 = 0, max2 = 0;
	f[x] = 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs(y, x); f[x]++;
		if(f[y] > max1) max2 = max1, max1 = f[y];
		else if(f[y] > max2) max2 = f[y];
	}
	f[x] += max(max1 - 1, 0);
	dp[x] = f[x] + max(max2 - 1, 0) + (x != 1);
	ans = max(ans, dp[x]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}