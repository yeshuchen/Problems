#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct edge{
	int x, y, z;
}a[N];
int n, m, tot;
int f[N], d[N], ver[N], val[N], nxt[N], head[N];
inline int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
inline void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
inline void dfs(int x, int fa)
{
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i], z = val[i];
		if(y == fa) continue;
		if(d[x] == z)
		{
			if(z == 1) d[y] = n;
			else d[y] = 1;
		} 
		else d[y] = z;
		dfs(y, x);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++)
		cin >> a[i].x >> a[i].y >> a[i].z;
	for(int i = 1; i <= m; i++)
	{
		int fx = find(a[i].x), fy = find(a[i].y);
		if(fx == fy) continue;
		f[fx] = fy;
		add(a[i].x, a[i].y, a[i].z);
		add(a[i].y, a[i].x, a[i].z);
	}
	d[1] = 1;
	dfs(1, 0);
	for(int i = 1; i <= n; i++) cout << d[i] << '\n';
	return 0;
}