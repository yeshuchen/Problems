#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, inf = 2e9;
int n, S, T;
int a[N], tot = 1;
bool vis[N];
int ver[N], nxt[N], head[N], limit[N];
void add(int x, int y, int z)
{
	ver[++tot] = y;
	limit[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
void addedge(int x, int y, int z)
{
	add(x, y, z);
	add(y, x, 0);
}
int dep[N], cur[N];
bool bfs()
{
	memset(dep, 0, (T + 1) * sizeof(int));
	dep[S] = 1; queue<int> q;
	q.push(S);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i];
			if(limit[i] && !dep[y])
			{
				dep[y] = dep[x] + 1;
				q.push(y);
			}
		}
	}
	return dep[T];
}
int dfs(int x, int flow)
{
	if(x == T || !flow) return flow;
	int res = 0;
	for(int i = cur[x]; i; i = nxt[i])
	{
		cur[x] = i;
		int y = ver[i], v;
		if(dep[y] == dep[x] + 1 && (v = dfs(y, min(flow - res, limit[i]))))
		{
			res += v;
			limit[i] -= v;
			limit[i ^ 1] += v;
			if(res == flow) return flow;
		}
	}
	return res;
}
int ans;
vector<int> v[N], p[N];
void dfs2(int x)
{
	vis[x] = 1;
	p[ans].push_back(x);
	for(int y : v[x])
		if(!vis[y]) dfs2(y);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 2; i <= 20000; i++)
	{
		if(vis[i]) continue;
		for(int j = 2 * i; j <= 20000; j += i)
			vis[j] = 1;
	}
	S = n + 1; T = S + 1;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		if(a[i] & 1)
		{
			addedge(S, i, 2);
			for(int j = 1; j <= n; j++)
				if(!vis[a[i] + a[j]])
					addedge(i, j, 1);
		}
		else addedge(i, T, 2);
	}
	while(bfs())
	{
		memcpy(cur + 1, head + 1, T * sizeof(int));
		ans += dfs(S, inf);
	}
	if(ans != n) {cout << "Impossible"; return 0;}
	for(int i = 1; i <= n; i++)
		if(a[i] & 1)
		{
			for(int j = head[i]; j; j = nxt[j])
				if(limit[j ^ 1])
					v[i].push_back(ver[j]), v[ver[j]].push_back(i);
		}
	ans = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			ans++;
			dfs2(i);
		}
	}
	cout << ans << '\n';
	for(int i = 1; i <= ans; i++)
	{
		cout << p[i].size() << ' ';
		for(int x : p[i]) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}