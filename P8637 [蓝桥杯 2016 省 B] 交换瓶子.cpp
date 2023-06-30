#include<bits/stdc++.h>
using namespace std;
int n, p[10005], vis[10005];
inline void dfs(int x)
{
	if(vis[x]) return;
	vis[x] = 1;
	dfs(p[x]);
}
int cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> p[i];
	for(int i = 1; i <= n; i++)
		if(!vis[i])
			dfs(i), cnt++;
	cout << n - cnt;
	return 0;
}