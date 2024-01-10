#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
int n, m, tot;
double val[N];
int ver[N], nxt[N], head[N];
void add(int x, int y, double z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
bool visit[N];
int vis[N], cnt[N];
double dis[N], v[N];
bool SPFA(int x, double w)
{
	memset(vis, 0, (n + 1) * sizeof(int));
	memset(cnt, 0, (n + 1) * sizeof(int));
	memset(dis, 0x3f, sizeof(dis));
	queue<int> q;
	q.push(x); dis[x] = 0;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		vis[x] = 0; visit[x] = 1;
		for(int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i];
			if(dis[x] + w * val[i] - v[y] < dis[y])
			{
				dis[y] = dis[x] + w * val[i] - v[y];
				if(!vis[y]) q.push(y), vis[y] = 1;
				cnt[y]++;
				if(cnt[y] > n) return true;
			}
		}
	}
	return false;
}
bool check(double x)
{
	memset(visit, 0, (n + 1) * sizeof(int));
	for(int i = 1; i <= n; i++)
		if(!visit[i])
			if(SPFA(i, x)) return true;
	return false;
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> v[i];
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	double l = 1e-6, r = 1e6;
	while(r - l > 1e-9)
	{
		double mid = (l + r) / 2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout << fixed << setprecision(2) << l;
	return 0;
}
/*
v[i] - mid * z[i] >= 0
mid * 
*/