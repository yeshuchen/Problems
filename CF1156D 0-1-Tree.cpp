#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;
int n, tot, ans;
int ver[N], val[N], nxt[N], head[N];
int f[N][2];
void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
void dfs1(int x, int fa)
{
	f[x][0] = f[x][1] = 0;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i], z = val[i];
		if(y == fa) continue;
		dfs1(y, x);
		if(z) f[x][1] += f[y][1] + 1;
		else f[x][0] += f[y][0] + f[y][1] + 1;
	}
}
void dfs2(int x, int fa, int z)
{
	if(!z) f[x][0] = f[fa][0] + f[fa][1] - f[x][1];
	else f[x][1] = f[fa][1];
	ans += f[x][0] + f[x][1];
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs2(y, x, val[i]);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
		add(y, x, z);
	}
	dfs1(1, 0);
	ans = f[1][0] + f[1][1];
	for(int i = head[1]; i; i = nxt[i])
		dfs2(ver[i], 1, val[i]);
	cout <<  ans;
	return 0;
}