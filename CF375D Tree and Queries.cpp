#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, maxn = 2e5 + 1;
int n, m, tot;
int a[N], col[N];
int ver[N], nxt[N], head[N];
struct BIT {
	int c[maxn + 5];
	void add(int x, int v) {for(int i = x; i <= maxn; i += (i & -i)) c[i] += v;}
	int ask(int x) {int res = 0; for(int i = x; i; i -= (i & -i)) res += c[i]; return res;}
} t;
vector< pair<int, int> > v[N];
void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int sz[N], son[N], ans[N], cnt[N];

void dfs(int x, int fa)
{
	sz[x] = 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs(y, x);
		sz[x] += sz[y];
		if(sz[y] > sz[son[x]]) son[x] = y;
	}
}
void merge(int x, int fa, int v)
{
	t.add(cnt[col[x]] + 1, -1);
	cnt[col[x]] += v;
	t.add(cnt[col[x]] + 1, 1);
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		merge(y, x, v);
	}
}
void dsu(int x, int fa)
{
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa || y == son[x]) continue;
		dsu(y, x); merge(y, x, -1);
	}
	if(son[x]) dsu(son[x], x);
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa || y == son[x]) continue;
		merge(y, x, 1);
	}
	t.add(cnt[col[x]] + 1, -1);
	cnt[col[x]]++;
	t.add(cnt[col[x]] + 1, 1);
	for(auto ele : v[x])
		ans[ele.second] = t.ask(maxn) - t.ask(ele.first);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> col[i];
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	for(int i = 1; i <= m; i++)
	{
		int x, k;
		cin >> x >> k;
		v[x].push_back(make_pair(k, i));
	}
	dfs(1, 0); dsu(1, 0);
	for(int i = 1; i <= m; i++) cout << ans[i] << '\n';
	return 0;
}