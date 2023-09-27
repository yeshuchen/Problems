#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, INF = 1e9;
int n, m, k, tot, cnt;
int ls[N], rs[N], id[N << 2];
int in[N], ver[N], val[N], nxt[N], head[N];
inline void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
	in[y]++;
}
inline void build(int p, int l, int r)
{
	int mid = l + r >> 1;
	if(l == r)
	{
		id[l] = p;
		return;
	}
	ls[p] = ++cnt; rs[p] = ++cnt;
	build(ls[p], l, mid);
	build(rs[p], mid + 1, r);
	add(p, ls[p], 0);
	add(p, rs[p], 0);
}
inline void addedge(int p, int l, int r, int L, int R, int point)
{
	if(L <= l && r <= R)
	{
		add(point, p, 1);
		return;
	}
	int mid = l + r >> 1;
	if(L <= mid) addedge(ls[p], l, mid, L, R, point);
	if(R > mid) addedge(rs[p], mid + 1, r, L, R, point);
}
bool flag = 1;
bool vis[N], ins[N];
int f[N], tmp[N];
inline void dfs(int x)
{
	vis[x] = ins[x] = 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(ins[y])
		{
			flag = 0;
			return;
		}
		if(!vis[y]) dfs(y);
	}
	ins[x] = 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	cnt = 1;
	build(1, 1, n);
	for(int i = 1, x, y; i <= m; i++)
		cin >> x >> y, f[id[x]] = tmp[id[x]] = y;
	for(int i = 1; i <= k; i++)
	{
		int l, r, s;
		cin >> l >> r >> s;
		int pl = l; cnt++;
		for(int j = 1; j <= s; j++)
		{
			int x;
			cin >> x;
			add(id[x], cnt, 0);
			if(pl <= x - 1) addedge(1, 1, n, pl, x - 1, cnt);
			pl = x + 1;
		}
		if(pl <= r) addedge(1, 1, n, pl, r, cnt);
	}
	for(int i = 1; i <= cnt; i++)
		if(!f[i]) f[i] = INF;
	for(int i = 1; i <= cnt; i++)
		if(!vis[i])
		{
			dfs(i);
			if(!flag)
			{
				cout << "NIE";
				return 0;
			}
		}
	queue<int> q;
	for(int i = 1; i <= cnt; i++)
		if(!in[i]) q.push(i);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i], z = val[i];
			if(tmp[y] > f[x] - z) {cout << "NIE"; return 0;}
			f[y] = min(f[y], f[x] - z); in[y]--;
			if(!in[y]) q.push(y);
			if(f[y] < 1) {cout << "NIE"; return 0;}
		}
	}
	cout << "TAK\n";
	for(int i = 1; i <= n; i++)
		cout << f[id[i]] << ' ';
	return 0;
}