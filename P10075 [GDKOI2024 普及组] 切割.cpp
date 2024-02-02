#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
int n, m, tot;
int x[N], y[N], vis[N];
ll a[N], ans[N];
int ver[N], nxt[N], head[N];
mt19937 rd;
void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void dfs(int x, int fa)
{
	vis[x] = 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		if(vis[y])
		{
			if(!ans[i + i % 2]) ans[i + i % 2] = rd();
			a[x] ^= ans[i + i % 2];
		}
		else
		{
			dfs(y, x);
			ans[i + i % 2] = a[y];
			a[x] ^= ans[i + i % 2];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> x[i] >> y[i];
		add(x[i], y[i]);
		add(y[i], x[i]);
	}
	dfs(1, 0);
	int q; cin >> q;
	while(q--)
	{
		int k, flag = 0; cin >> k;
		for(int i = 1; i <= k; i++) cin >> a[i];
		for(int i = 1; i < (1 << k); i++)
		{
			ll res = 0;
			for(int j = 1; j <= k; j++)
				if(i & (1 << j - 1)) res ^= ans[a[j] * 2];
			if(!res) flag = 1;
		}
		cout << (!flag ? "ymqOAO\n" : "Bob\n");
	}
	return 0;
}