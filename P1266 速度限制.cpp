#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 2e6, M = 500 * 155;
int n, m, tot;
int ver[N], nxt[N], head[N];
double val[N], dis[M];
void add(int x, int y, double z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
int pos[M];
bool vis[M];
void dij(int x)
{
	for(int i = 1; i <= 500 * n; i++) dis[i] = 2e9;
	priority_queue< pair<double, int> > q;
	dis[x] = 0; q.push(make_pair(0, x));
	while(!q.empty())
	{
		int x = q.top().second; q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i]; double z = val[i];
			if(dis[x] + z < dis[y])
			{
				dis[y] = dis[x] + z; pos[y] = x;
				q.push(make_pair(-dis[y], y));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int ed;
	cin >> n >> m >> ed; ed++;
	for(int i = 1; i <= m; i++)
	{
		int x, y, v, len;
		cin >> x >> y >> v >> len;
		x++; y++;
		for(int i = 500; i; i--)
		{
			if(v) add((i - 1) * n + x, (v - 1) * n + y, 1.0 * len / v);
			else add((i - 1) * n + x, (i - 1) * n + y, 1.0 * len / i);
		}
	}
	dij(69 * n + 1); int mn = ed;
	for(int i = 1; i <= 500; i++)
		if(dis[(i - 1) * n + ed] < dis[mn]) mn = (i - 1) * n + ed;
	stack<int> s;
	while(mn)
	{
		s.push((mn - 1) % n + 1);
		mn = pos[mn];
	}
	while(!s.empty()) cout << s.top() - 1 << ' ', s.pop();
	// cout << dis[mn] << ' ' << mn << '\n';
	return 0;
}