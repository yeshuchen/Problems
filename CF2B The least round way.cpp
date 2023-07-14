#include<bits/stdc++.h>
using namespace std;
int n, ans = INT_MAX;
int a[1005][1005], f[1005][1005];
bool d[1005][1005], ANS[1005][1005];
inline void solve()
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(i == 1 && j == 1) continue;
			if(i == 1)
			{
				f[i][j] += f[i][j - 1];
				d[i][j] = 0;
				continue;
			}
			if(j == 1)
			{
				f[i][j] += f[i - 1][j];
				d[i][j] = 1;
				continue;
			}
			if(f[i - 1][j] < f[i][j - 1]) f[i][j] += f[i - 1][j], d[i][j] = 1;
			else f[i][j] += f[i][j - 1], d[i][j] = 0;
		}
	int res = f[n][n];
	if(ans > res)
	{
		ans = res;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				ANS[i][j] = d[i][j];
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			f[i][j] = 0;
}
int X, Y;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if(!a[i][j])
				X = i, Y = j;
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(!a[i][j]) f[i][j] = 5;
			while(a[i][j] && a[i][j] % 2 == 0)
				a[i][j] /= 2, f[i][j]++;
		}
	solve();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(!a[i][j]) f[i][j] = 5;
			while(a[i][j] && a[i][j] % 5 == 0)
				a[i][j] /= 5, f[i][j]++;
		}
	solve();
	if(X && ans > 1)
	{
		cout << 1 << '\n';
		for(int i = 1; i < X; i++)
			cout << 'D';
		for(int i = 1; i < n; i++)
			cout << 'R';
		for(int i = X; i < n; i++)
			cout << 'D';
		return 0;
	}
	cout << ans << '\n';
	int x = n, y = n;
	stack<char> s;
	for(int i = 1; i <= 2 * n - 2; i++)
	{
		if(ANS[x][y] == 0) s.push('R'), y--;
		else s.push('D'), x--;
	}
	while(!s.empty()) cout << s.top(), s.pop();
	return 0;
}