#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, cnt, tot;
int ver[N], val[N], nxt[N], head[N];
inline void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
bool vis[N];
int d[N], cost[N];
inline void SPFA()
{
	for(int i = 2; i <= n; i++) d[i] = INT_MAX;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		vis[x] = 0;
		for(int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i], z = val[i];
			if(d[y] > d[x] + 1)
			{
				d[y] = d[x] + 1;
				cost[y] = cost[x] + z;
				if(!vis[y]) q.push(y), vis[y] = 1;
			}
			else if(d[y] == d[x] + 1)
			{
				cost[y] = min(cost[y], cost[x] + z);
				if(!vis[y]) q.push(y), vis[y] = 1;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if(!z) add(x, y, 1), add(y, x, 1);
		else add(x, y, -1), add(y, x, -1);
		cnt += z;
	}
	SPFA();
	cout << cnt + cost[n];
	return 0;
}