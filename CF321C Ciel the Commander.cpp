#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
char ans[N];
int n, rt, sum, sz[N], mx[N];
int tot, ver[N], nxt[N], head[N];
void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void dfs(int x, int fa)
{
	sz[x] = 1; sum++;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa || ans[y]) continue;
		dfs(y, x);
		sz[x] += sz[y];
	}
}
void findrt(int x, int fa)
{
	mx[x] = sum - sz[x];
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa || ans[y]) continue;
		mx[x] = max(mx[x], sz[y]);
		findrt(y, x);
	}
	if(mx[x] < mx[rt]) rt = x;
}
void solve(int x, int pos)
{
	ans[x] = 'A' + pos - 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(ans[y]) continue;
		rt = 0; sum = 0;
		dfs(y, x);
		findrt(y, x);
		solve(rt, pos + 1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	mx[0] = INT_MAX;
	dfs(1, 0);
	findrt(1, 0);
	solve(rt, 1);
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}