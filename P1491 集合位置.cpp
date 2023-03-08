#include<bits/stdc++.h>
using namespace std;
const int N = 40005;
int n, m, tot;
int v[N], xd[N], yd[N];
int ver[N], nxt[N], head[N];
double d[N], val[N];
inline double dis(int x, int y) {return sqrt((xd[x] - xd[y]) * (xd[x] - xd[y]) + (yd[x] - yd[y]) * (yd[x] - yd[y]));}
inline void add(int x, int y)
{
	ver[++tot] = y;
	val[tot] = dis(x, y);
	nxt[tot] = head[x];
	head[x] = tot;
}
bool f[205][205];
inline void dij(int flag)
{
	priority_queue< pair<int, int> > q;
	for(int i = 2; i <= n; i++) d[i] = 1e9;
	q.push(make_pair(d[1], 1));
	while(!q.empty())
	{
		int x = q.top().second; q.pop();
		for(int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i];
			if(f[x][y]) continue;
			double z = val[i];
			if(d[x] + z < d[y])
			{
				d[y] = d[x] + z;
				if(flag) v[y] = x;
				q.push(make_pair(-d[y], y));
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> xd[i] >> yd[i];
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	dij(1);
	int pos = n; double ans = INT_MAX;
	while(v[pos])
	{
		f[v[pos]][pos] = 1;
		dij(0);
		ans = min(ans, d[n]);
		f[v[pos]][pos] = 0;
		pos = v[pos];
	}
	if(ans == INT_MAX) {cout << -1; return 0;}
	printf("%.2lf", ans);
	return 0;
}