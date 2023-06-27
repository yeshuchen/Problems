#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int x_1[N], x_2[N], y_1[N], y_2[N];
inline bool check(int x, int y)
{
	if(x_1[x] == x_1[y] && x_2[x] == x_2[y] || y_1[x] == y_1[y] && y_2[x] == y_2[y]) return false;
	if(x_1[x] == x_2[x])
		return (x_1[y] <= x_1[x] && x_1[x] <= x_2[y] && y_1[x] <= y_1[y] && y_1[y] <= y_2[x]);
	else
		return (x_1[x] <= x_1[y] && x_1[y] <= x_2[x] && y_1[y] <= y_1[x] && y_1[x] <= y_2[y]);
}
int tot;
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
} 
bool vis[N];
int match[N];
inline int dfs(int x)
{
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(vis[y]) continue;
		vis[y] = 1;
		if(!match[y] || dfs(match[y]))
		{
			match[y] = x;
			return 1;
		}
	}
	return 0;
}
int a[N];
int main()
{
	int ans = 0;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> x_1[i] >> y_1[i] >> x_2[i] >> y_2[i];
		if(x_1[i] > x_2[i]) swap(x_1[i], x_2[i]);
		if(y_1[i] > y_2[i]) swap(y_1[i], y_2[i]);
		if(x_1[i] == x_2[i]) a[i] = 1;
		else a[i] = 2;
	}
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			if(check(i, j)) add(i, j + n), add(j, i + n);
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == 1) continue;
		for(int j = n + 1; j <= 2 * n; j++) vis[j] = 0;
		ans += dfs(i);
	}
	cout << n - ans;
	return 0;
}