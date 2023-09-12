#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5, inf = 2e9;
int n, m, q, tot;
int ver[N], nxt[N], val[N], head[N];
inline void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
} 
struct node {
	int x, val;
};
int cnt[N];
int dis[N], ret;
bool vis[N];
bool operator > (node a, node b) {return a.val > b.val;} 
inline void dijkstra()
{
	priority_queue< node, vector<node>, greater<node> > q;
	for(int i = 1; i <= ret; i++) dis[i] = inf, vis[i] = 0;
	q.push({1, 0}); dis[1] = 0;
	while(!q.empty())
	{
		node t = q.top(); q.pop(); int x = t.x;
		if(vis[t.x]) continue;
		vis[t.x] = 1;
		for(int i = head[x]; i; i = nxt[i])
		{	
			int z = val[i], y = ver[i];
			if(dis[x] + z < dis[y])
			{
				dis[y] = dis[x] + z;
				q.push({y, dis[y]});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	ret = 2 * n;
	for(int i = 1; i <= m; i++)
	{
		int k;
		cin >> k; 
		for(int j = 1, x; j <= k; j++)
		{
			ret++;
			cin >> x;
			if(j == 1) add(x, ret, 0);
			else 
			{
				add(ret - 1, ret, 1);
				add(x, ret, 0);
				add(ret, x + n, 0);
			}
		}
		ret++;
	}
	// for(int i = 1; i <= ret; i++) cout << id[i] << ' ';
	// cout << '\n';
	dijkstra(); cnt[0] = dis[n + n];
	// for(int i = 0; i <= n; i++) cout << cnt[i] << ' ';
	for(int i = 1; i <= 20; i++)
	{
		for(int j = 2; j <= n; j++) add(1, j, dis[n + j]);
		dijkstra();
		cnt[i] = dis[2 * n];
	}
	for(int i = 1; i <= q; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		long long ans = LLONG_MAX;
		for(int p = 0; p <= c; p++)
			if(cnt[p] != inf)
				ans = min(ans, 1ll * cnt[p] * a + p * b);
		cout << ans << '\n';
	}
	return 0;
} 