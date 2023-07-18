#include<bits/stdc++.h>
using namespace std;
int n, m, id = 1;
int vis[100005], nxt[100005];
int match[100005];
vector<int> g[100005];
inline int dfs(int x)
{
	for(int i = 0; i < g[x].size(); i++)
	{
		int y = g[x][i];
		if(vis[y] == id) continue;
		vis[y] = id;
		if(!match[y] || dfs(match[y]))
		{
			match[y] = x;
			return 1;
		}
	}
	return 0;
}
int f[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		g[y].push_back(x + n);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++, id++)
		ans += dfs(i);
	for(int i = 1; i <= 2 * n; i++)
		f[i] = i;
	for(int i = n + 1; i <= 2 * n; i++)
		if(match[i])
			f[i - n] = match[i], nxt[match[i]] = i - n;
	for(int i = 1; i <= n; i++)
	{
		int x = i;
		stack<int> s;
		if(f[x] == x)
		{
			while(x)
			{
				s.push(x);
				x = nxt[x];
			}
			while(!s.empty()) cout << s.top() << ' ', s.pop();
			cout << '\n';
		}
	}
	cout << n - ans;
	return 0;
}