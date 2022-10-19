#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, tot;
int f[N], a[N];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
inline void dfs(int x, int fa)
{
	f[x] = a[x];
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs(y, x);
		f[x] += max(f[y], 0);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	dfs(1, 0);
	int ans = INT_MIN;
	for(int i = 1; i <= n; i++)
		ans = max(ans, f[i]);
	cout << ans;
	return 0;
}