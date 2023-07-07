#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, m, k, tot;
int ver[N], val[N], nxt[N], head[N];
inline void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
int res, dfn[N];
int dep[N], f[N][20];
struct node{
	int p, d;
} t[N];
int num[N], cnt[N];
inline void dfs(int x, int fa, int z)
{
	f[x][0] = fa;
	dep[x] = dep[fa] + 1;
	dfn[x] = ++res; num[x] = z;
	for(int i = 1; i < 20; i++)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i], z = val[i];
		if(y == fa) continue;
		dfs(y, x, z);
	}
}
inline int LCA(int x, int y)
{
	if(dep[x] < dep[y]) swap(x, y);
	int tmp = dep[x] - dep[y];
	for(int i = 19; i >= 0; i--)
		if(tmp & (1 << i))
			x = f[x][i];
	if(x == y) return x;
	for(int i = 19; i >= 0; i--)
		if(f[x][i] != f[y][i])
			x = f[x][i], y = f[y][i];
	return f[x][0];
}
inline int cmp(node x, node y) {return x.d < y.d;}
inline void ADD(int x, int y)
{
	int lca = LCA(x, y);
	cnt[x]++; cnt[y]++;
	cnt[lca] -= 2;
}
inline void DFS(int x, int fa)
{
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		DFS(y, x);
		cnt[x] += cnt[y];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y, i);
		add(y, x, i);
	}
	dfs(1, 0, 0);
	for(int i = 1; i <= m; i++)
	{
		int s;
		cin >> s;
		for(int j = 1; j <= s; j++)
		{
			cin >> t[j].p;
			t[j].d = dfn[t[j].p];
		}
		sort(t + 1, t + s + 1, cmp);
		t[s + 1] = t[1];
		for(int j = 1; j <= s; j++)
			ADD(t[j].p, t[j + 1].p);
	}
	DFS(1, 0);
	vector<int> ans;
	for(int i = 1; i <= n; i++)
		if(cnt[i] >= 2 * k)
			ans.push_back(num[i]);
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	return 0;
}