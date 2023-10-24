#include<bits/stdc++.h>
using namespace std;
int n;
int a[505][505], ans[505];
void dfs(int x)
{
	for(int i = 1; i <= n; i++)
	{
		if(ans[i] || !a[x][i]) continue;
		ans[i] = 1; dfs(i);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++) ans[j] = 0;
		dfs(i);
		for(int j = 1; j <= n; j++) cout << ans[j] << ' ';
		cout << '\n';
	}
	return 0;
}