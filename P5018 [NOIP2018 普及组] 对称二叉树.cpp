#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, sz[N], ls[N], rs[N];
int ans = 1;
int vis[N];
int a[N], hs[N], hsh[N];
bool dfs(int x, int y)
{
	if(x == -1 && y == -1) return true;
	if(x == -1 || y == -1 || a[x] != a[y]) return false;
	return dfs(ls[x], rs[y]) && dfs(rs[x], ls[y]);
}
int cnt(int x)
{
	int sz = 1;
	if(x == -1) return 0;
	sz += cnt(ls[x]) + cnt(rs[x]);
	return sz;
}
mt19937 rnd(time(0));
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= 1000; i++) hs[i] = rnd();
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> ls[i] >> rs[i];
	for(int i = 1; i <= n; i++)
		if(dfs(i, i)) ans = max(ans, cnt(i));
	cout << ans;
	return 0;
}