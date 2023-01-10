#include<bits/stdc++.h>
#define ri register int
using namespace std;
const int N = 1e5 + 5, inf = 2e9;
int n, m, r;
struct Edge{
	int x, y, z;
}e[N];
int id[N], ine[N], vis[N], pre[N];
int zhuliu()
{
	int ans = 0;
	while(1)
	{
		for(ri i = 1; i <= n; i++) ine[i] = inf;
		for(int i = 1; i <= m; i++)
		{
			int x = e[i].x, y = e[i].y;
			if(x != y && e[i].z < ine[y])
				ine[y] = e[i].z, pre[y] = x;
		}
		for(ri i = 1; i <= n; i++)
			if(i != r && ine[i] == inf)
				return -1;
		int cnt = 0;
		for(ri i = 1; i <= n; i++) vis[i] = id[i] = 0;
		for(ri i = 1; i <= n; i++)
		{
			if(i == r) continue;
			ans += ine[i];
			int v = i;
			while(vis[v] != i && !id[v] && v != r)
			{
				vis[v] = i;
				v = pre[v];
			}
			if(!id[v] && v != r)
			{
				id[v] = ++cnt;
				for(int x = pre[v]; x != v; x = pre[x])
					id[x] = cnt;
			}
		}
		if(cnt == 0) break;
		for(int i = 1; i <= n; i++)
			if(!id[i]) id[i] = ++cnt;
		for(int i = 1; i <= m; i++)
		{
			int x = e[i].x, y = e[i].y;
			e[i].x = id[x]; e[i].y = id[y];
			if(id[x] != id[y]) e[i].z -= ine[y];
		}
		r = id[r]; n = cnt;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for(int op = 1; op <= T; op++)
	{
		cout << "Case " << op << ": ";
		cin >> n >> m >> r;
		for(int i = 1; i <= m; i++)
			cin >> e[i].x >> e[i].y >> e[i].z;
		r++;
		for(int i = 1; i <= m; i++)
			e[i].x++, e[i].y++;
		int ans = zhuliu();
		if(ans == -1) cout << "impossible\n";
		else cout << ans << '\n';
	}
	return 0;
}