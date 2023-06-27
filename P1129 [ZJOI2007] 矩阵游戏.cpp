#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int T, n;
int vis[N], match[N];
vector<int> g[N];
inline bool dfs(int x)
{
	for(int i = 0; i < g[x].size(); i++)
	{
		int y = g[x][i];
		if(vis[y]) continue;
		vis[y] = 1;
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
	cin >> T;
	while(T--)
	{
		int ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) g[i].clear(), match[i] = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				bool f;
				cin >> f;
				if(f) g[i].push_back(j);
			}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++) vis[j] = 0;
			ans += dfs(i);
		}
		if(ans != n) cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}