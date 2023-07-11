#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, tot;
int a[N], m[N], m1[N], vis[N];
int ver[N << 1], nxt[N << 1], head[N];
struct node {
	int len, x;
};
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int ans = 0;
vector<node> v[N];
inline void dfs(int x, int fa)
{
	if(a[x] != 1) v[x].push_back((node) {1, a[x]});
	vector<int> p, u, po;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		po.push_back(y);
		dfs(y, x);
	}
	for(int i = 0; i < po.size(); i++)
	{
		int y = po[i];
		for(int j = 0; j < v[y].size(); j++)
		{
			int gcd = __gcd(v[y][j].x, a[x]);
			if(gcd == 1) continue;
			u.push_back(gcd);
			m1[gcd] = max(m1[gcd], v[y][j].len + 1);
			for(int k = 0; k < p.size(); k++)
			{
				int tmp = __gcd(gcd, p[k]);
				if(tmp == 1) continue;
				ans = max(ans, v[y][j].len + m[p[k]] + 1);
			}
		}
		for(int j = 0; j < v[y].size(); j++)
		{
			if(m[v[y][j].x])
			{
				m[v[y][j].x] = max(m[v[y][j].x], v[y][j].len);
				continue;
			}
			p.push_back(v[y][j].x);
			m[v[y][j].x] = v[y][j].len;
		}
	}
	for(int i = 0; i < u.size(); i++)
	{
		int gcd = u[i];
		if(!vis[gcd])
		{
			v[x].push_back((node) {m1[gcd], gcd});
			vis[gcd] = 1;
			m1[gcd] = 0;
		}
	}
	for(int i = 0; i < u.size(); i++) vis[u[i]] = 0;
	for(int i = 0; i < p.size(); i++) m[p[i]] = 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < v[i].size(); j++)
			ans = max(ans, v[i][j].len);
	cout << ans;
	return 0;
}