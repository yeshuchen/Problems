#include<bits/stdc++.h>
using namespace std;
int n, m, f[15][15];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			f[i][j] = f[i - 1][j - 1] + f[i - 1][j] * j;
	for(int i = 1; i <= m; i++)
		f[n][m] *= i;
	cout << f[n][m];
	return 0;
}