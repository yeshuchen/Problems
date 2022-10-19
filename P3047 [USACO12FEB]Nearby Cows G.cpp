#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5;
int n, k, tot;
ll f[N][25];
int nxt[N], ver[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
inline void dfs(int x, int fa)
{
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs(y, x);
		for(int j = 1; j <= k; j++) f[x][j] += f[y][j - 1];
	}
}
inline void dfs2(int x, int fa)
{
	for(int i = k; i >= 2; i--)
		f[x][i] = f[fa][k - (k - i + 1)] + f[x][i] - f[x][i - 2];
	f[x][1] = f[fa][0] + f[x][1];
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs2(y, x);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	for(int i = 1; i <= n; i++) cin >> f[i][0];
	dfs(1, 0);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= k + 1; j++)
			f[i][j] += f[i][j - 1];
	for(int i = head[1]; i; i = nxt[i])
		dfs2(ver[i], 1);
	for(int i = 1; i <= n; i++) cout << f[i][k] << '\n';
	return 0;
}