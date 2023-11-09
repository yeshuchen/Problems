#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;
int n, m;
struct node {
	int x, y, z, id;
} e[N];
int ans, f[N];
bool cmp(node x, node y) {return x.z < y.z;}
bool cmp2(node x, node y) {return x.id < y.id;}
int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
int tot, ver[N], val[N], nxt[N], head[N];
void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
int dep[N], fa[N][17], mx[N][17];
void dfs(int x, int Fa)
{
	fa[x][0] = Fa;
	dep[x] = dep[Fa] + 1;
	for(int i = 1; i < 17; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1], mx[x][i] = max(mx[x][i - 1], mx[fa[x][i - 1]][i - 1]);
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i], z = val[i];
		if(y == Fa) continue;
		mx[y][0] = val[i];
		dfs(y, x);
	}
}
int LCA(int x, int y)
{
	int maxn = 0;
	if(dep[x] < dep[y]) swap(x, y);
	int tmp = dep[x] - dep[y];
	for(int i = 0; i < 17; i++)
		if(tmp & (1 << i))
			maxn = max(maxn, mx[x][i]), x = fa[x][i];
	if(x == y) return maxn;
	for(int i = 16; i >= 0; i--)
		if(fa[x][i] != fa[y][i])
		{
			maxn = max({maxn, mx[x][i], mx[y][i]});
			x = fa[x][i];
			y = fa[y][i];
		}
	return max({maxn, mx[x][0], mx[y][0]});
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) f[i] = i;
 	for(int i = 1; i <= m; i++)
		cin >> e[i].x >> e[i].y >> e[i].z, e[i].id = i;
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= m; i++)
	{
		int x = find(e[i].x), y = find(e[i].y);
		if(x == y) continue;
		f[y] = x; ans += e[i].z;
		add(e[i].x, e[i].y, e[i].z);
		add(e[i].y, e[i].x, e[i].z);
	}
	dfs(1, 0);
	sort(e + 1, e + m + 1, cmp2);
	for(int i = 1; i <= m; i++)
		cout << ans + e[i].z - LCA(e[i].x, e[i].y) << '\n';
	return 0;
}