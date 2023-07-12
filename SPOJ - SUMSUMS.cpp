#include<bits/stdc++.h>
#define int long long
const int mod = 98765431;
using namespace std;
struct matrix {
	int r, c;
	int a[4][4];
} ans, base, bsc;
int sum;
matrix operator * (const matrix &a, const matrix &b)
{
	matrix c;
	memset(c.a, 0, sizeof(c.a));
	c.r = a.r; c.c = b.c;
	for(int i = 1; i <= a.r; i++)
		for(int j = 1; j <= c.c; j++)
			for(int k = 1; k <= a.c; k++)
				c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % mod;
	return c;
}
int n, t, a[50005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> t;
	for(int i = 1; i <= n; i++)
		cin >> a[i], sum += a[i];
	sum %= mod;
	ans.r = 1; ans.c = 2;
	base.r = base.c = 2;
	bsc.r = 2; bsc.c = 2;
	memset(bsc.a, 0, sizeof(bsc.a));
	memset(base.a, 0, sizeof(base.a));
	bsc.a[1][1] = -1; bsc.a[2][1] = 1; bsc.a[2][2] = n - 1;
	base.a[1][1] = base.a[2][2] = 1;
	while(t)
	{
		if(t & 1) base = base * bsc;
		bsc = bsc * bsc;
		t >>= 1;
	}
	for(int i = 1; i <= n; i++)
	{
		ans.a[1][1] = a[i];
		ans.a[1][2] = sum;
		cout << (ans * base).a[1][1] << '\n';
	}
	return 0;
}