#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, k, tot;
int f[N][105], g[N][105];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
inline void dfs(int x, int fa)
{
	f[x][0] = 1; g[x][0] = 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs(y, x);
		
		for(int j = k; j >= 0; j--)
			for(int l = 0; l + j <= k; l++)
			{
				g[x][j + l + 1] = max(g[x][j + l + 1], f[x][j] + g[y][l]);
				g[x][j + l + 2] = max(g[x][j + l + 2], g[x][j] + f[y][l]);
			}
		for(int j = k; j >= 0; j--)
			for(int l = 0; j + l <= k; l += 2)
			{
				if(j & 1) continue;
				f[x][j + l + 2] = max(f[x][j + l + 2], f[x][j] + f[y][l]);
			}
		
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
		x++; y++;
		add(x, y);
		add(y, x);
	}
	dfs(1, 0); 
	int ans = 0;
	for(int i = 1; i <= k; i++) ans = max(ans, g[1][i]);
	cout << ans;
	return 0;
}
/*
显然，我们可以设f[i][j]表示从节点i出发
经过j步并且回到点i最多可以经过的格点数
g[i][j]表示从节点i出发，经过j步最多可以经过的格点数
*/