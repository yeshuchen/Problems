#include<bits/stdc++.h>
#define d(i) (i == n ? 1 : i + 1)
#define u(i) (i == 1 ? n : i - 1)
using namespace std;
int n, m;
int a[205][205], f[205][205], pos[205][205];
int main()
{
	while(cin >> n >> m)
	{
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> a[i][j], f[i][j] = INT_MAX, pos[i][j] = INT_MAX;
		for(int i = 1; i <= n; i++)
			f[i][m] = a[i][m], pos[i][m] = 0;
		for(int j = m - 1; j >= 1; j--)
			for(int i = 1; i <= n; i++)
			{
				if(f[i][j + 1] + a[i][j] <= f[i][j] && i <= pos[i][j] || f[i][j + 1] + a[i][j] < f[i][j]) pos[i][j] = i, f[i][j] = f[i][j + 1] + a[i][j];
				if(f[d(i)][j + 1] + a[i][j] <= f[i][j] && d(i) <= pos[i][j] || f[d(i)][j + 1] + a[i][j] < f[i][j]) pos[i][j] = d(i), f[i][j] = f[d(i)][j + 1] + a[i][j];
				if(f[u(i)][j + 1] + a[i][j] <= f[i][j] && u(i) <= pos[i][j] || f[u(i)][j + 1] + a[i][j] < f[i][j]) pos[i][j] = u(i), f[i][j] = f[u(i)][j + 1] + a[i][j];
			}
		int ans = 1, p = 1;
		vector<int> v;
		for(int i = 2; i <= n; i++)
			if(f[ans][1] > f[i][1])
				ans = i;
		v.push_back(f[ans][1]);
		while(pos[ans][p])
			v.push_back(ans), ans = pos[ans][p], p++;
		v.push_back(ans);
		for(int i = 1; i < v.size() - 1; i++)
			cout << v[i] << ' ';
		cout << v[v.size() - 1] << '\n';
		cout << v[0] << '\n';
	}
	return 0;
}