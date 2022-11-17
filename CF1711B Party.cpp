#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int T, n, m;
int a[N];
vector<int> g[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; i++) cin >> a[i], g[i].clear();
		for(int i = 1; i <= m; i++)
		{
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(!(m & 1))
		{
			cout << 0 << '\n';
			continue;
		}
		int ans = INT_MAX;
		for(int i = 1; i <= n; i++)
			if(g[i].size() & 1)
				ans = min(ans, a[i]);
		for(int i = 1; i <= n; i++)
		{
			int di = g[i].size();
			if(!(di & 1))
				for(int j = 0; j < g[i].size(); j++)
					if(di % 2 == 0 && g[g[i][j]].size() % 2 == 0)
						ans = min(ans, a[i] + a[g[i][j]]);
		}
		cout << ans << '\n';
	}
	return 0;
}
