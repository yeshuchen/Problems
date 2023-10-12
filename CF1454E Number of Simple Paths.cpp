#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int T, n;
bool vis[N];
int sz[N], deg[N];
vector<int> g[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++) g[i].clear(), deg[i] = 0, sz[i] = 1, vis[i] = 0;
		for(int i = 1; i <= n; i++)
		{
			int x, y;
			cin >> x >> y;
			deg[x]++; deg[y]++;
			g[x].emplace_back(y);
			g[y].emplace_back(x);
		}
		queue<int> q;
		for(int i = 1; i <= n; i++)
			if(deg[i] == 1)
				q.push(i);
		while(!q.empty())
		{
			int x = q.front(); q.pop();
			vis[x] = 1;
			for(int y : g[x])
			{
				sz[y] += sz[x];
				if(--deg[y] == 1)
					q.push(y);
			}
		}
		long long ans = 0, sum = 0;
		for(int i = 1; i <= n; i++)
			if(!vis[i])
			{
				ans += sz[i] * (sz[i] - 1) / 2;
				ans += sz[i] * sum * 2;
				sum += sz[i];
			}
		cout << ans << '\n';
	}
	return 0;
}