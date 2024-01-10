#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9;
int n, m, t;
int a[305][305];
int ksm(int a, int b)
{
	int base = 1;
	while(b)
	{
		if(b & 1) base = 1ll * base * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return base;
}
void add(int &x, int y) {x = ((x + y) % mod + mod) % mod;}
int det()
{
	bool flag = 0;
	for(int i = 2; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			while(a[i][i])
			{
				int q = a[j][i] / a[i][i];
				for(int k = i; k <= n; k++)
					a[j][k] = (a[j][k] - q * a[i][k] % mod + mod) % mod;
				swap(a[i], a[j]); flag ^= 1;
			}
			swap(a[i], a[j]); flag ^= 1;
		}
	}
	int ans = 1;
	for(int i = 2; i <= n; i++) ans = 1ll * ans * a[i][i] % mod;
	return (flag ? (mod - ans) % mod : ans);
}
char ch[105][105];
int dx[4] = {0, 1};
int dy[4] = {1, 0};
int res, id[105][105];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			cin >> ch[i][j];
			if(ch[i][j] == '.') id[i][j] = ++res;
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(ch[i][j] == '*') continue;
			for(int d = 0; d < 2; d++)
			{
				int nx = i + dx[d], ny = j + dy[d];
				if(nx > n || ny > m || ch[nx][ny] == '*') continue;
				add(a[id[i][j]][id[nx][ny]], -1);
				add(a[id[nx][ny]][id[i][j]], -1);
				add(a[id[i][j]][id[i][j]], 1);
				add(a[id[nx][ny]][id[nx][ny]], 1);
			}
		}
	n = res;
	cout << det();
	return 0;
}