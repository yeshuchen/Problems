#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 8e5 + 5;
int T, n, m;
struct edge{
    int x, y, z;
}a[N];
struct Edge{
    int tot;
    int ver[N], val[N], nxt[N], head[N];
    inline void init()
    {
		tot = 0;
        memset(head, 0, sizeof(head));
        memset(nxt, 0, sizeof(nxt));
    }
	inline void add(int x, int y)
	{
		ver[++tot] = y;
		nxt[tot] = head[x];
		head[x] = tot;
	}
    inline void add(int x, int y, int z)
    {
        ver[++tot] = y;
        val[tot] = z;
        nxt[tot] = head[x];
        head[x] = tot;
    }
}E, e;
int d[N], vis[N];
void dij(int x)
{
    for(int i = 1; i <= n; i++) vis[i] = 0;
	priority_queue< pair<int, int> > q;
	q.push(make_pair(d[1], 1));
	for(int i = 2; i <= n; i++) d[i] = INT_MAX;
	while(!q.empty())
	{
		int x = q.top().second; q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = E.head[x]; i; i = E.nxt[i])
		{
			int y = E.ver[i], z = E.val[i];
			if(d[y] > d[x] + z)
			{
				d[y] = d[x] + z;
				q.push(make_pair(-d[y], y));
			}
		}
	}
}
int fath[N][24], minn[N];
int p[N], f[N], cnt;
bool cmp(edge x, edge y){return x.z > y.z;}
inline int find(int k){return f[k] == k ? k : f[k] = find(f[k]);}
inline void dfs(int x, int fa)
{
	if(x <= n) minn[x] = d[x];
	else minn[x] = INT_MAX;
	fath[x][0] = fa; 
	for(int i = 1; i <= 18; i++) fath[x][i] = fath[fath[x][i - 1]][i - 1];
	for(int i = e.head[x]; i; i = e.nxt[i])
	{
		int y = e.ver[i];
		if(y == x) continue;
		dfs(y, x);
		minn[x] = min(minn[y], minn[x]);
	}
}
inline int query(int x, int high)
{
	for(int i = 18; i >= 0; i--)
		if(p[fath[x][i]] > high)
			x = fath[x][i];
	return minn[x];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--)
    {
        E.init(); e.init();
        cin >> n >> m;
		cnt = n;
        for(int i = 1; i <= m; i++)
        {
            int x, y, z, h;
            cin >> x >> y >> z >> h;
            a[i].x = x; a[i].y = y; a[i].z = h;
            E.add(x, y, z);
            E.add(y, x, z);
        }
		for(int i = 1; i <= 2 * n; i++) f[i] = i;
		dij(1);
		sort(a + 1, a + m + 1, cmp);
		for(int i = 1; i <= m; i++)
		{
			int fx = find(a[i].x), fy = find(a[i].y);
			if(fx == fy) continue;
			p[++cnt] = a[i].z;
			f[fx] = f[fy] = cnt;
			e.add(cnt, fx);
			e.add(cnt, fy);
		}
		dfs(cnt, 0);
		int q, k, s, lastans = 0;
		cin >> q >> k >> s;
		while(q--)
		{
			int v, l;
			cin >> v >> l;
			v = (v + k * lastans - 1) % n + 1;
			l = (l + k * lastans) % (s + 1);
			lastans = query(v, l);
			cout << lastans << '\n';
		}
    }
    return 0;
}