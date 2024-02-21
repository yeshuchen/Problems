#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
char ch[N];
int n, m, q, X, Y;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct edge {
	int x, y, z;
} e[N];
int dis[N], g[N][2];
int f[N], val[N], dep[N], fa[N][20];
int ID(int x, int y) {return (x - 1) * m + y;}
int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
void get_dis()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			if(ch[ID(i, j)] == '#')
			{
				X = i; Y = j;
				break;
			}
		if(X) break;
	}
	queue< pair<int, int> > q;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			dis[ID(i, j)] = -1;
			if(ch[ID(i, j)] == 'v')
				q.push(make_pair(i, j)), dis[ID(i, j)] = 0;
		}
	while(!q.empty())
	{
		int x = q.front().first, y = q.front().second; q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 1 || nx > n || ny < 1 || ny > m || dis[ID(nx, ny)] > -1) continue;
			dis[ID(nx, ny)] = dis[ID(x, y)] + 1;
			q.push(make_pair(nx, ny));
		}
	}
}
vector<int> v[N];
void dfs(int x, int fat)
{
	fa[x][0] = fat;
	dep[x] = dep[fat] + 1;
	for(int y : v[x]) dfs(y, x);
}
int LCA(int x, int y)
{
	if(dep[x] < dep[y]) swap(x, y);
	int tmp = dep[x] - dep[y];
	for(int i = 0; i <= 19; i++)
		if(tmp & (1 << i)) x = fa[x][i];
	if(x == y) return x;
	for(int i = 19; i >= 0; i--)
		if(fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	int res = 0, tot = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			cin >> ch[ID(i, j)];
			g[ID(i, j)][0] = ++res;
			g[ID(i, j)][1] = ++res;
		}
	for(int i = 1; i <= res; i++) f[i] = i;
	get_dis();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(ch[ID(i, j)] == '#') continue;
			for(int k = 0; k < 2; k++)
			{
				int ni = i + dx[k], nj = j + dy[k];
				int xx = ID(i, j), yy = ID(ni, nj);
				if(ni < 1 || ni > n || nj < 1 || nj > m || ch[yy] == '#') continue;
				if(j == Y && nj == Y + 1 && i <= X)
				{
					e[++tot] = {g[xx][0], g[yy][1], min(dis[xx], dis[yy])};
					e[++tot] = {g[xx][1], g[yy][0], min(dis[xx], dis[yy])};
				}
				else
				{
					e[++tot] = {g[xx][0], g[yy][0], min(dis[xx], dis[yy])};
					e[++tot] = {g[xx][1], g[yy][1], min(dis[xx], dis[yy])};
				}
			}
		}
	sort(e + 1, e + tot + 1, [](edge x, edge y) {return x.z > y.z;});
	for(int i = 1; i <= tot; i++)
	{
		int x = find(e[i].x), y = find(e[i].y);
		if(x == y) continue;
		val[++res] = e[i].z;
		v[res].push_back(x);
		v[res].push_back(y);
		f[x] = f[y] = f[res] = res;
	}
	dfs(res, 0);
	for(int j = 1; j <= 19; j++)
		for(int i = 1; i <= res; i++)
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		cout << val[LCA(g[ID(x, y)][0], g[ID(x, y)][1])] << '\n';
	}
	return 0;
}