#include<bits/stdc++.h>
using namespace std;
int n, m, d, tot;
int vis[100005];
int v[100005], c[100005], k[100005];
int ver[100005], nxt[100005], head[100005];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int id;
int mat[100005];
inline bool dfs(int x)
{
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(vis[y] == id) continue;
		vis[y] = id;
		if(!mat[y] || dfs(mat[y]))
		{
			mat[y] = x;
			return 1;
		}
	}
	return 0;
}
int us[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> v[i], v[i]++;
	for(int i = 1; i <= n; i++) cin >> c[i];
	cin >> d;
	for(int i = 1; i <= d; i++)
		cin >> k[i], us[k[i]] = 1;
	for(int i = 1; i <= n; i++)
	{
		if(us[i]) continue;
		add(v[i], c[i]);
	}
	stack<int> ans;
	int lastans = 1;
	for(int i = d; i >= 1; i--)
	{
		for(int j = lastans; j <= n; j++)
		{
			id++;
			if(dfs(j)) lastans++;
			else break;
		}
		add(v[k[i]], c[k[i]]);
		ans.push(lastans - 1);
	}
	while(!ans.empty()) cout << ans.top() << '\n', ans.pop();
	return 0;
}