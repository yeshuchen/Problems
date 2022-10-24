#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, tot, cnt;
int ver[N], nxt[N], head[N];
struct node{
	int x, y;
}ans[N];
inline bool cmp(node x, node y) {return (x.x == y.x) ? x.y < y.y : x.x < y.x;}
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int res, dfn[N], low[N];
inline void tarjan(int x, int fa)
{
	dfn[x] = low[x] = ++res;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(!dfn[y])
		{
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
			if(low[y] > dfn[x])
			{
				ans[++cnt].x = min(x, y);
				ans[cnt].y = max(x, y);
			}
		}
		else if(y != fa) low[x] = min(low[x], dfn[y]); 
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(cin >> n)
	{
		cnt = res = tot = 0;
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(head, 0, sizeof(head));
		for(int i = 1; i <= n; i++)
		{
			int x, y, k;
			char ch;
			cin >> x;
			cin >> ch >> k >> ch;
			for(int j = 1; j <= k; j++)
				cin >> y, add(x + 1, y + 1), add(y + 1, x + 1);
		}
		for(int i = 1; i <= n; i++)
		{
			if(!dfn[i])
				tarjan(i, 0);
		}
		sort(ans + 1, ans + cnt + 1, cmp);
		cout << cnt << " critical links\n";
		for(int i = 1; i <= cnt; i++)
			cout << ans[i].x - 1 << " - " << ans[i].y - 1 << '\n';
		cout << '\n';
	}
	return 0;
}