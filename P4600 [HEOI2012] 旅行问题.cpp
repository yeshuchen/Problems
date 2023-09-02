#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, mod = 1e9 + 7;
char s[N];
int n, m, res;
int ans[N], tr[N][27];
vector<int> v[N];
int tot, ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
inline void insert(char *s, int p)
{
	v[p].push_back(0); int pos = 0, len = strlen(s + 1);
	for(int i = 1; i <= len; i++)
	{
		int x = s[i] - 'a';
		if(!tr[pos][x])
		{
			tr[pos][x] = ++res;
			ans[res] = (ans[pos] * 26ll + x) % mod;
		}
		v[p].push_back(tr[pos][x]); pos = tr[pos][x];
	}
}
int fail[N];
inline void build()
{
	queue<int> q;
	for(int i = 0; i < 26; i++)
		if(tr[0][i]) q.push(tr[0][i]);
	while(!q.empty())
	{
		int x = q.front(); q.pop(); add(fail[x], x);
		for(int i = 0; i < 26; i++)
		{
			if(!tr[x][i]) tr[x][i] = tr[fail[x]][i];
			else
			{
				fail[tr[x][i]] = tr[fail[x]][i];
				q.push(tr[x][i]);
			}
		}
	}
}
int fa[N], sz[N], son[N], top[N], dep[N];
inline void dfs1(int x)
{
	sz[x] = 1; dep[x] = dep[fa[x]] + 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		fa[y] = x; dfs1(y); sz[x] += sz[y];
		if(sz[y] > sz[son[x]]) son[x] = y;
	}
}
inline void dfs2(int x, int tp)
{
	top[x] = tp;
	if(son[x]) dfs2(son[x], tp);
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == son[x]) continue;
		dfs2(y, y);
	}
}
inline int lca(int x, int y)
{
	while(top[x] != top[y])
	{
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s + 1;
		insert(s, i);
	}
	build(); cin >> m;
	dfs1(0); dfs2(0, 0);
	for(int i = 1; i <= m; i++)
	{
		int p, l, q, r;
		cin >> p >> l >> q >> r;
		cout << ans[lca(v[p][l], v[q][r])] << '\n';
	}
	return 0;
}