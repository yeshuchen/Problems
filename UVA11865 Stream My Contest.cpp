#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, inf = 2e9;
struct Edge{
	int x, y, z, w;
}e[N], E[N];
int T, n, m, C, root = 1;
int ine[N], pre[N], vis[N], id[N];
inline bool zhuliu(int line)
{
	int ans = 0;
	while(1)
	{
		for(int i = 1; i <= n; i++) ine[i] = inf;
		for(int i = 1; i <= m; i++)
		{
			int x = E[i].x, y = E[i].y, z = E[i].z;
			if(z < line) continue;
			if(x != y && ine[y] > E[i].w)
				ine[y] = E[i].w, pre[y] = x;
		}
		for(int i = 1; i <= n; i++)
			if(i != root && ine[i] == inf)
				return 0;
		int cnt = 0;
		for(int i = 1; i <= n; i++) vis[i] = id[i] = 0;
		for(int i = 1; i <= n; i++)
		{
			if(i == root) continue; 
			int v = i; ans += ine[i];
			while(vis[v] != i && !id[i] && v != root)
			{
				vis[v] = i;
				v = pre[v];
			}
			if(!id[v] && v != root)
			{
				id[v] = ++cnt;
				for(int x = pre[v]; x != v; x = pre[x])
					id[x] = cnt;
			}
		}
		if(!cnt) break;
		for(int i = 1; i <= n; i++)
			if(!id[i])
				id[i] = ++cnt;
		for(int i = 1; i <= m; i++)
		{
			int x = E[i].x, y = E[i].y;
			E[i].x = id[x]; E[i].y = id[y];
			if(id[x] != id[y]) E[i].w -= ine[y];
		}
		root = id[root]; n = cnt;
	}
	return (ans <= C);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		root = 1;
		int l = 0, r = 0;
		cin >> n >> m >> C;
		int p = n;
		for(int i = 1; i <= m; i++)
		{
			cin >> e[i].x >> e[i].y >> e[i].z >> e[i].w;
			e[i].x++; e[i].y++;
		}
		for(int i = 1; i <= m; i++) E[i] = e[i];
		for(int i = 1; i <= m; i++)
			r = max(r, e[i].z);
		int ans = zhuliu(0);
		if(!ans)
		{
			cout << "streaming not possible.\n";
			continue;
		}
		while(l <= r)
		{
			for(int i = 1; i <= m; i++) E[i] = e[i];
			root = 1; n = p;
			int mid = l + r >> 1;
			if(zhuliu(mid)) l = mid + 1;
			else r = mid - 1;
		}
		cout << l - 1 << " kbps\n";
	}
	return 0;
}