#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, m, p, tot;
int f[10005][25];
bool vis[10005][25];
int ver[N], val[N], nxt[N], head[N];
inline void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
inline void dij()
{
	memset(f, 0x3f, sizeof(f)); f[1][0] = 0;
	priority_queue< pair<int, pair<int, int> > > q;
	q.push(make_pair(f[1][0], make_pair(1, 0)));
	while(!q.empty())
	{
		int x = q.top().second.first, k = q.top().second.second; q.pop();
		if(vis[x][k]) continue;
		vis[x][k] = 1;
		for(int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i], z = val[i];
			if(f[x][k] + z < f[y][k])
			{
				f[y][k] = f[x][k] + z;
				q.push(make_pair(-f[y][k], make_pair(y, k))); 
			}
			if(f[x][k] < f[y][k + 1] && k < p)
			{
				f[y][k + 1] = f[x][k];
				q.push(make_pair(-f[y][k + 1], make_pair(y, k + 1)));
			}
		}
	}	
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> p;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
		add(y, x, z);
	}
	dij();
	int ans = LLONG_MAX;
	for(int i = 0; i <= p; i++)
		ans = min(ans, f[n][i]);
	cout << ans;
	return 0;
}