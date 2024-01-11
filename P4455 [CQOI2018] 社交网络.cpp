#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e4 + 7;
int n, m;
int a[305][305];
void add(int &x, int y) {x = ((x + y) % mod + mod) % mod;}
int ksm(int a, int b)
{
	int base = 1;
	while(b)
	{
		if(b & 1) base = base * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return base;
}
signed main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> y >> x;
		add(a[x][y], -1);
		add(a[y][y], 1);
	}
	int flag = 0;
	for(int i = 2; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
			if(a[j][i]) {swap(a[i], a[j]); flag ^= 1;}
		int inv = ksm(a[i][i], mod - 2);
		for(int j = i + 1; j <= n; j++)
		{
			int q = a[j][i] * inv % mod;
			for(int k = i; k <= n; k++)
				add(a[j][k], -q * a[i][k] % mod);
		}
	}
	int ans = 1;
	for(int i = 2; i <= n; i++) ans = ans * a[i][i] % mod;
	cout << (flag ? (mod - ans) % mod : ans);
	return 0;
}