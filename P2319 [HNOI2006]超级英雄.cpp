#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m;
bool vis[N];
vector<int> g[N];
int match[N], ans[N];
inline int dfs(int x)
{
	for(int i = 0; i < g[x].size(); i++)
	{
		int y = g[x][i];
		if(vis[y]) continue; vis[y] = 1;
		if(!match[y] || dfs(match[y]))
		{
			match[y] = x;
			return 1;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> m >> n;
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		g[i].push_back(x + 1);
		g[i].push_back(y + 1);
	}
	int ANS = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++) vis[j] = 0;
		if(dfs(i)) ANS++;
		else break;
	}
	cout << ANS << '\n';
	for(int i = 1; i <= m; i++)
		ans[match[i]] = i;
	for(int i = 1; i <= m; i++)
		if(ans[i])
			cout << ans[i] - 1 << '\n';
	return 0;
}