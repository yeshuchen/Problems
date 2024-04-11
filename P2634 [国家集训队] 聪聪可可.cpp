#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, tot;
int c1[N], c2[N];
int ver[N], val[N], nxt[N], head[N];
void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
int rt, ans, sum;
int vis[N], dis[N], sz[N];
void get_root(int x, int fa)
{
	sz[x] = 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(vis[y] || y == fa) continue;
		get_root(y, x);
		sz[x] += sz[y];
	}
	if(max(sz[x], sum - sz[x]) < max(sz[rt], sum - sz[rt])) rt = x;
}
void dfs(int x, int fa)
{
	c1[dis[x] % 3]++;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i], z = val[i];
		if(y == fa || vis[y]) continue;
		dis[y] = dis[x] + z; dfs(y, x);
	}
}
void solve(int x)
{
	rt = x;
	get_root(x, 0);
	get_root(rt, 0);
	vis[rt] = 1; dis[rt] = 0;
	c2[0] = 1; c2[1] = c2[2] = 0;
	for(int i = head[rt]; i; i = nxt[i])
	{
		int y = ver[i], z = val[i];
		if(vis[y]) continue;
		c1[0] = c1[1] = c1[2] = 0;
		dis[y] = dis[rt] + z;
		dfs(y, rt);
		ans = ans + 2 * (c1[0] * c2[0] + c1[1] * c2[2] + c2[1] * c1[2]);
		c2[0] += c1[0]; c2[1] += c1[1]; c2[2] += c1[2];
	}
	for(int i = head[rt]; i; i = nxt[i])
	{
		int y = ver[i];
		if(vis[y]) continue;
		sum = sz[y]; solve(y);
	}
}
int main()
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
	sum = n; solve(1); ans += n;
	int g = __gcd(ans, n * n);
	cout << ans / g << '/' << n * n / g;
	return 0;
}