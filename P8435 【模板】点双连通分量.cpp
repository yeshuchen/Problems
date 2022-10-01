#include<bits/stdc++.h>
using namespace std;
const int N = 4e6 + 5;
int n, m, tot, top, res, cnt;
int ver[N], nxt[N], head[N];
int stk[N], dfn[N], low[N];
bool vis[N];
vector<int> g[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void tarjan(int x, int fa)
{
	stk[++top] = x;
	dfn[x] = low[x] = ++res;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(!dfn[y])
		{
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
			if(dfn[x] <= low[y])
			{
				cnt++;
				g[cnt].push_back(x);
				vis[x] = 1;
				while(stk[top+1] != y)
					g[cnt].push_back(stk[top]), vis[stk[top--]]=1;
			}
		}
		else if(y != fa) low[x] = min(low[x], dfn[y]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	for(int i = 1; i <= n; i++)
		if(!dfn[i])
			tarjan(i, 0);
	for(int i = 1; i <= n; i++)
		if(!vis[i])
			g[++cnt].push_back(i);
	cout << cnt << '\n';
	for(int i = 1; i <= cnt; i++)
	{
		cout << g[i].size() << ' ';
		for(int j = 0; j < g[i].size(); j++)
			cout << g[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}