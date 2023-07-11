#include<bits/stdc++.h>
using namespace std;
int n, m, ans;
int x[100005];
int f[105][105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		cin >> x[i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> f[i][j];
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				f[i][j] = min(f[i][k] + f[k][j], f[i][j]);	
	for(int i = 1; i < m; i++)
		ans += f[x[i]][x[i + 1]];
	cout << ans;
	return 0;
}