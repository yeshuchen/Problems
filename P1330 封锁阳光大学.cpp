#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m;
int cnt[3], vis[N];
int tot, ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
inline bool dfs(int x, int c)
{
	vis[x] = c; cnt[c]++;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(vis[x] == vis[y]) return false;
		if(!vis[y] && !dfs(y, 3 - c)) return false;
	}
	return true;
}
int ans;
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
	for(int i = 1; i <= n; i++)
	{
		cnt[1] = cnt[2] = 0;
		if(vis[i]) continue;
		bool f = dfs(i, 1);
		if(!f) {cout << "Impossible\n"; return 0;}
		else ans += min(cnt[1], cnt[2]);
	}
	cout << ans;
	return 0;
}