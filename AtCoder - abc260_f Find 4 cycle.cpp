#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int ans[3005][3005];
vector<int> v[300005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++)
	{
		int x, y;
		cin >> x >> y;
		y -= n; v[x].push_back(y);
		for(int j = 0; j < v[x].size() - 1; j++)
		{
			int &u = ans[v[x][j]][y];
			if(u)
			{
				cout << u << ' ' << v[x][j] + n << ' ' << x << ' ' << y + n;
				return 0;
			}
			u = x;
			ans[y][v[x][j]] = x;
		}
	}
	cout << -1;
	return 0;
}