#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, tot;
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int cnt, l[N], r[N];
inline void dfs(int x, int fa)
{
	bool flag = 0; l[x] = INT_MAX;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs(y, x); flag = 1;
		l[x] = min(l[x], l[y]), r[x] = max(r[x], r[y]);
	}
	if(!flag) l[x] = r[x] = ++cnt; 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++)
		cout << l[i] << ' ' << r[i] << '\n';
	return 0;
}