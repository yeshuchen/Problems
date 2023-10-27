#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5, inf = 2e9;
int n, m, tot = 1;
struct edge {
	int y, z, w, nxt;
};
int S, T, pos[N];
struct Graph {
	int head[N];
	edge e[N];
	void add(int x, int y, int z, int w)
	{
		e[++tot] = {y, z, w, head[x]};
		head[x] = tot;
	}
	void addedge(int x, int y, int z, int w)
	{
		add(x, y, z, w);
		add(y, x, 0, -w);	
	}
	int dis[N], vis[N], pre[N], flow[N];
	bool SPFA()
	{
		memset(vis, 0, (T + 1) * sizeof(int));
		memset(dis, 0x3f, (T + 1) * sizeof(int));
		flow[S] = inf; flow[T] = 0; queue<int> q;
		q.push(S); dis[S] = 0;
		while(!q.empty())
		{
			int x = q.front(); q.pop();
			vis[x] = 0;
			for(int i = head[x]; i; i = e[i].nxt)
			{
				int y = e[i].y, w = e[i].w;
				if(e[i].z && dis[y] > dis[x] + w)
				{
					flow[y] = min(flow[x], e[i].z);
					dis[y] = dis[x] + w; pre[y] = i;
					if(!vis[y]) vis[y] = 1, q.push(y);
				}
			}
		}
		return flow[T];
	}
	int ans, maxflow;
	void update()
	{
		maxflow += flow[T];
		for(int i = T; i != S; i = e[pre[i] ^ 1].y)
		{
			e[pre[i]].z -= flow[T];
			e[pre[i] ^ 1].z += flow[T];
			ans += flow[T] * e[pre[i]].w;
		}
	}
} e, E;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	S = 2 * n + 1; T = S + 1;
	for(int i = 1; i <= n; i++)
	{
		e.addedge(S, i, 1, 0);
		for(int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			e.addedge(i, j + n, 1, -x);
		}
		e.addedge(i + n, T, 1, 0);
	}
	int cnt = 0;
	E = e;
	while(E.SPFA()) E.update();
	cout << -E.ans << '\n';
	int res = E.ans;
	for(int i = 1; i <= n; i++)
	{
		for(int j = e.head[i]; j; j = e.e[j].nxt)
			if(E.e[j ^ 1].z && E.e[j].y != S) pos[i] = j;
	}
	for(int i = 1; i <= n; i++)
	{
		E = e;
		E.e[pos[i]].z = 0;
		while(E.SPFA()) E.update();
		if(E.ans != res) cout << i << ' ' << e.e[pos[i]].y - n << '\n';
	}
	return 0;
}