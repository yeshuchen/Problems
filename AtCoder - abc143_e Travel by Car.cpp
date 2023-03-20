#include<bits/stdc++.h>
using namespace std;
const long long maxn = 1e18;
int n, m, l;
long long f[305][305];
int main()
{
	cin >> n >> m >> l;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j) f[i][j] = maxn;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		f[x][y] = f[y][x] = z;
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(f[i][k] + f[k][j] < f[i][j])
					f[i][j] = f[i][k] + f[k][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(i == j) f[i][j] = 0;
			else if(f[i][j] <= l) f[i][j] = 1;
			else f[i][j] = maxn;
		}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(f[i][k] + f[k][j] < f[i][j])
					f[i][j] = f[i][k] + f[k][j];
	int q;
	cin >> q;
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		if(f[x][y] == maxn) cout << -1 << '\n';
		else cout << f[x][y] - 1 << '\n';
	}
	return 0;
}