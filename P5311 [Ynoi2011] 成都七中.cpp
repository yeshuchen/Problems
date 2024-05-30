#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, tot, col[N];
int head[N], nxt[N], ver[N];
void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

struct node {
    int l, r, x, id;
} q[N];
int rt, sum, f[N], ans[N];
int sz[N], mx[N], vis[N];
vector<int> g[N];
struct query {
    int l, r, x;
};
vector<query> v[N];

void get_root(int x, int fa)
{
    sz[x] = 1; mx[x] = 0;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa || vis[y]) continue;
        get_root(y, x);
        sz[x] += sz[y];
        mx[x] = max(mx[x], sz[y]);
    }
    mx[x] = max(mx[x], sum - sz[x]);
    if(mx[x] < mx[rt] || !rt) rt = x;
}
void build(int x)
{
    vis[x] = 1;
    get_root(x, 0);
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(vis[y]) continue;
        rt = 0; sum = sz[y]; 
        get_root(y, x);
        g[x].push_back(rt);
        f[rt] = x;
        build(rt);
    }
}

vector<query> v1, v2;
bool cmp(query x, query y) {return x.r < y.r;}
void dfs(int x, int fa, int l, int r)
{
    for(int i = 0; i < v[x].size(); i++)
        if(!ans[v[x][i].x] && l >= v[x][i].l && r <= v[x][i].r)
            v1.push_back({v[x][i].l, v[x][i].r, v[x][i].x});
	v2.push_back({l, r, col[x]});
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(vis[y] || y == fa) continue;
        dfs(y, x, min(l, y), max(r, y));
    }
}

int c[N], lst[N];
void Add(int x, int v) {for(int i = x; i <= n; i += (i & -i)) c[i] += v;}
int ask(int x) {int res = 0; for(int i = x; i; i -= (i & -i)) res += c[i]; return res;}
void solve(int x)
{
	v1.clear(); v2.clear();
    dfs(x, 0, x, x);
	int pos = 0;
	vector<int> C;
	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);
	for(int i = 0; i < v1.size(); i++)
	{
		while(pos < v2.size() && v2[pos].r <= v1[i].r)
		{
			if(!lst[v2[pos].x]) Add(v2[pos].l, 1), lst[v2[pos].x] = v2[pos].l, C.push_back(v2[pos].x);
			else if(lst[v2[pos].x] < v2[pos].l) Add(lst[v2[pos].x], -1), Add(v2[pos].l, 1), lst[v2[pos].x] = v2[pos].l;
			pos++;
		}
		ans[v1[i].x] = ask(n) - ask(v1[i].l - 1);
	}
	vis[x] = 1;
	for(int x : C) Add(lst[x], -1), lst[x] = 0;
    for(int y : g[x]) solve(y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> col[i];
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    rt = 0; sum = n;
    get_root(1, 0);
    int mid = rt; build(rt);
    rt = mid;
    for(int i = 1; i <= m; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        v[x].push_back((query){l, r, i});
    }
    memset(vis, 0, sizeof(vis));
    solve(rt);
    for(int i = 1; i <= m; i++) cout << ans[i] << '\n';
    return 0;
}