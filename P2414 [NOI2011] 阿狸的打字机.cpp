#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int len, st, tot, m;
char s[N];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int cnt;
struct trie {
	int res = 0, end[N], id[N], vis[100005][30];
	int tr[100005][30], f[N], fail[N];
	inline int insert(int p, char c)
	{
		int x = c - 'a';
		if(tr[p][x]) return tr[p][x];
		tr[p][x] = ++res; f[res] = p;
		return res;
	}
	inline void build()
	{
		queue<int> q;
		for(int i = 0; i < 26; i++)
		{
			if(tr[0][i]) q.push(tr[0][i]);
			else vis[0][i] = 1;
		}
		while(!q.empty())
		{
			int x = q.front(); q.pop(); add(fail[x], x);
			for(int i = 0; i < 26; i++)
			{
				if(!tr[x][i]) tr[x][i] = tr[fail[x]][i], vis[x][i] = 1;
				else
				{
					fail[tr[x][i]] = tr[fail[x]][i];
					q.push(tr[x][i]);
				}
			}
		}
	}
} TR;
struct BIT {
	int c[N], n;
	inline void add(int x, int k) {
		for(int i = x; i <= n; i += (i & -i)) c[i] += k;
	}
	inline int ask(int x) {
		int res = 0;
		for(int i = x; i; i -= (i & -i)) res += c[i];
		return res;
	}
} b;
bool book[N];
int ret, dfn[N], sz[N];
inline void dfs1(int x)
{
	book[x] = 1;
	dfn[x] = ++ret; sz[x] = 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(book[y]) continue;
		dfs1(y); sz[x] += sz[y];
	}
}
int tot1, Ver[N], Nxt[N], Val[N], Head[N];
inline void Add(int x, int y, int z)
{
	Ver[++tot1] = y;
	Val[tot1] = z;
	Nxt[tot1] = Head[x];
	Head[x] = tot1;
}
int ans[N];
inline void dfs2(int x)
{
	b.add(dfn[x], 1);
	if(TR.end[x])
	{
		for(int i = Head[x]; i; i = Nxt[i])
		{
			int y = TR.id[Ver[i]], z = Val[i];
			ans[z] = b.ask(dfn[y] + sz[y] - 1) - b.ask(dfn[y] - 1);
		}
	}
	for(int i = 0; i < 26; i++)
		if(!TR.vis[x][i]) dfs2(TR.tr[x][i]);
	b.add(dfn[x], -1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s + 1;
	len = strlen(s + 1);
	for(st = 1; st <= len; st++)
		if(s[st] != 'B' && s[st] != 'P')
			break;
	int p = TR.insert(p, s[st]);
	for(int i = st + 1; i <= len; i++)
	{
		if(s[i] == 'B') p = TR.f[p];
		else if(s[i] == 'P') TR.end[p] = ++cnt, TR.id[cnt] = p;
		else p = TR.insert(p, s[i]);
	}
	TR.build();
	dfs1(0); b.n = TR.res + 1;
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		Add(TR.id[y], x, i);
	}
	dfs2(0);
	for(int i = 1; i <= m; i++) cout << ans[i] << '\n';
	return 0;
}