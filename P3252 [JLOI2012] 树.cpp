#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, s, tot, ans;
int a[100005], ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int f[N];
inline void Dfs(int x, int fa)
{
	f[x] = fa;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		Dfs(y, x);
	}
}
inline void dfs(int x, int w)
{
	if(w >= s)
	{
		if(w == s) ans++;
		return;
	}
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == f[x]) continue;
		dfs(y, w + a[y]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> s;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	Dfs(1, 0);
	for(int i = 1; i <= n; i++)
		dfs(i, a[i]);
	cout << ans;
	return 0;
}