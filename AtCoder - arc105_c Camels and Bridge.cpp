#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int l, v;
}a[100005];
int n, m;
int ans = INT_MAX;
int w[50], p[50];
int d[50], in[50];
int sum[50], f[50][50];
int t[100005], maxn[100005];
inline bool cmp(node x, node y) {return x.v < y.v;}
inline void solve()
{
	memset(f, 0, sizeof(f));
	memset(d, 0, sizeof(d));
	for(int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + p[i], in[i] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
		{
			int dis = sum[j] - sum[i - 1];
			f[i][j] = maxn[lower_bound(t + 1, t + m + 1, dis) - t - 1];
			if(!f[i][j]) continue;
			in[j]++;
		}
	queue<int> q;
	for(int i = 1; i <= n; i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = 1; i <= n; i++)
		{
			if(!f[x][i]) continue;
			d[i] = max(d[i], d[x] + f[x][i]);
			if(!--in[i]) q.push(i);
		}
	}
	ans = min(ans, d[n]);
	return;
}
bool vis[10];
inline void dfs(int step)
{
	if(step > n) {solve(); return;}
	for(int i = 1; i <= n; i++)
		if(!vis[i])
		{
			p[step] = w[i]; 
			vis[i] = 1;
			dfs(step + 1);
			vis[i] = 0;
		}
}
int minpos = INT_MAX, maxpos;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> w[i], maxpos = max(maxpos, w[i]);
	for(int i = 1; i <= m; i++)
		cin >> a[i].l >> a[i].v, minpos = min(minpos, a[i].v);
	if(maxpos > minpos)
	{
		cout << -1;
		return 0;
	}
	sort(a + 1, a + m + 1, cmp);
	for(int i = 1; i <= m; i++)
		t[i] = a[i].v;
	for(int i = 1; i <= m; i++)
		maxn[i] = max(maxn[i - 1], a[i].l);
	dfs(1);
	cout << ans << '\n';
	return 0;
}