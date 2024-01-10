#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, m, T;
int dis[N];
int c[N], ans;
vector<int> g[N];
void bfs(int x)
{
	dis[x] = 0;
	queue<int> q;
	q.push(x);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		if(dis[x] >= ans) break;
		for(int y : g[x])
		{
			if(dis[y] > dis[x] + 1)
			{
				dis[y] = dis[x] + 1;
				q.push(y);
			}
		}
	}
}
int main()
{
	cin >> T;
	while(T--)
	{
		cin >> n >> c[1];
		for(int i = 1; i <= n; i++) g[i].clear(), dis[i] = INT_MAX;
		for(int i = 2; i <= n; i++) cin >> c[i];
		for(int i = 1; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		ans = INT_MAX;
		bfs(c[1]);
		for(int i = 2; i <= n; i++)
		{
			ans = min(ans, dis[c[i]]);
			bfs(c[i]);
			cout << ans << ' ';
		}
		cout << '\n';
	}
	return 0;
}