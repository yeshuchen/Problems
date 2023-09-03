#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, K, tot;
int ver[N], nxt[N], val[N], head[N];
inline void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
int rt, sum;
bool vis[N];
int sz[N], mx[N];
inline int findrt(int x, int fa)
{
	sz[x] = 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa || vis[y]) continue;
		sz[x] += findrt(y, x);
		mx[x] = max(sz[x], sum - sz[x]);
		if(mx[x] <= mx[rt])
			rt = x;
	}
	return sz[x];
}
int cnt;
int dis[N], dist[N];
inline void calcdis(int x, int fa)
{
	dis[++cnt] = dist[x];
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i], z = val[i];
		if(y == fa || vis[y]) continue;
		dist[y] = dist[x] + z;
		calcdis(y, x);
	}
}
int c[100005];
long long ans;
inline void cal(int x, int k)
{
	while(x <= K)
	{
		c[x] += k;
		x += (x & -x);
	}
}
inline int ask(int x)
{
	int res = 0;
	while(x)
	{
		res += c[x];
		x -= (x & -x);
	}
	return res;
}
inline void dfs(int x, int fa)
{
	vis[x] = 1; queue<int> q;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i], z = val[i];
		if(y == fa || vis[y]) continue;
		dist[y] = z;
		calcdis(y, x);
		for(int j = 1; j <= cnt; j++)
		{
			int w = dis[j];
			if(w > K) continue;
			ans += ask(K - w) + 1;
		}
		for(int j = 1; j <= cnt; j++)
		{
			if(dis[j] >= K) continue;
			q.push(dis[j]); cal(dis[j], 1);
		}
		cnt = 0;
	}
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		cal(x, -1);
	}
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa || vis[y]) continue;
		sum = sz[y]; rt = 0;
		findrt(y, x);
		findrt(rt, 0);
		dfs(rt, x);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		add(x, y, w);
		add(y, x, w);
	}
	cin >> K;
	sum = n; mx[rt] = INT_MAX;
	findrt(1, 0);
	findrt(rt, 0);
	dfs(rt, 0);
	cout << ans;
	return 0;
}