#include<bits/stdc++.h>
using namespace std;
const double ex = 1e-7;
int n, m, k, tot;
struct Edge {
	int nxt, y, typ;
	double z;
} e[1000005];
int head[100005];
inline void add(int x, int y, double z, int tp)
{
	e[++tot].nxt = head[x];
	e[tot].y = y;
	e[tot].z = z;
	e[tot].typ = tp;
	head[x] = tot;
}
double ans;
bool vis[1000005];
int cnt[1000005];
double dis[1000005];
inline bool spfa(double tmp)
{
	for(int i = 0; i <= n; i++)
		dis[i] = INT_MIN, cnt[i] = vis[i] = 0;
	queue<int> q;
	dis[n + 1] = cnt[n + 1] = 0;
	q.push(n + 1);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		vis[x] = 0;
		for(int i = head[x]; i; i = e[i].nxt)
		{
			int y = e[i].y;
			double z = e[i].z;
			if(e[i].typ == 1) z = log2(e[i].z - tmp);
			if(e[i].typ == 2) z = -log2(e[i].z + tmp);
			if(z + dis[x] > dis[y])
			{
				dis[y] = dis[x] + z;
				cnt[y] = cnt[x] + 1;
				if(cnt[y] >= n + 2) return true;
				if(!vis[y]) q.push(y), vis[y] = 1;
			}
		}
	}
	return false;
}
int main()
{
	double l = 0, r = 10;
	cin >> n >> m >> k;
	for(int i = 0; i <= n; i++) add(n + 1, i, 0, 3);
	for(int i = 1; i <= m; i++)
	{
		int op, x, y;
		double z;
		cin >> op >> x >> y >> z;
		add(y, x, z, op);
		if(op == 1) r = min(r, z);
	}
	for(int i = 1; i <= k; i++)
	{
		int x;
		double z;
		cin >> x >> z;
		add(0, x, log2(z), 3);
		add(x, 0, -log2(z), 3);
	}
	if(!spfa(0)) {cout << -1; return 0;}
	while(r - l > ex)
	{
		double mid = (l + r) / 2.0;
		if(spfa(mid)) l = (ans = mid) + ex;
		else r = mid;
	}
	printf("%.9lf", ans);
	return 0;
}