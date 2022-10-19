 #include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5;
int n, m, tot;
ll v[N], f[3005][3005], size[N];
int ver[N], val[N], nxt[N], head[N];
inline void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
inline void dfs(int x, int fa)
{
	for(int i = 1; i <= m; i++) f[x][i] = INT_MIN;
	if(v[x])
	{
		f[x][1] = v[x];
		size[x] = 1;
		return;
	}
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i], z = val[i];
		if(y == fa) continue;
		dfs(y, x); size[x] += size[y];
		for(int j = size[x]; j >= 0; j--)
			for(int k = 1; j + k <= size[x] && k <= size[y]; k++)
				f[x][j + k] = max(f[x][j + k], f[x][j] + f[y][k] - z);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n - m; i++)
	{
		int k, y, z;
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			cin >> y >> z;
			add(i, y, z);
		}
	}
	for(int i = 1; i <= m; i++) cin >> v[i + n - m];
	dfs(1, 0);
	for(int i = m; i >= 0; i--)
		if(f[1][i] >= 0)
		{
			cout << i;
			return 0;
		}
	return 0;
}