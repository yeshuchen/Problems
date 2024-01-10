#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, sz[N];
double ans[N];
vector<int> g[N];
void dfs(int x)
{
	sz[x] = 1;
	for(int y : g[x]) dfs(y), sz[x] += sz[y];
}
void dfs2(int x)
{
	int tmp = 0;
	for(int y : g[x]) tmp += sz[y];
	for(int y : g[x])
	{
		ans[y] = (tmp - sz[y]) / 2.0 + ans[x] + 1;
		dfs2(y);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		g[x].push_back(i);
	}
	dfs(1);
	ans[1] = 1.0;
	dfs2(1);
	for(int i = 1; i <= n; i++) cout << fixed << setprecision(1) << ans[i] << ' ';
	return 0;
}