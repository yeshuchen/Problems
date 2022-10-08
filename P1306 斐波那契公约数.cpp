#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e8;
int n, m;
int f[3][3];
int a[3][3], b[3][3], c[3][3];
inline void mule()
{
	memset(c, 0, sizeof(c));
	for(int i = 1; i <= 2; i++)
		for(int j = 1; j <= 2; j++)
			for(int k = 1; k <= 2; k++)
				c[i][j] += b[i][k] * a[k][j], c[i][j] %= mod;
	memcpy(b, c, sizeof(b));
}
inline void mul()
{
	memset(c, 0, sizeof(c));
	for(int i = 1; i <= 2; i++)
		for(int j = 1; j <= 2; j++)
			for(int k = 1; k <= 2; k++)
				c[i][j] += a[i][k] * a[k][j], c[i][j] %= mod;
	memcpy(a, c, sizeof(a));
}
inline void muler()
{
	memset(c, 0, sizeof(c));
	for(int i = 1; i <= 1; i++)
		for(int j = 1; j <= 2; j++)
			for(int k = 1; k <= 2; k++)
				c[i][j] += f[i][k] * b[k][j];
	cout << c[1][1] % mod;
}
inline void power(int b)
{
	while(b)
	{
		if(b & 1) mule();
		b >>= 1;
		mul();
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	n = __gcd(n, m);
	f[1][1] = f[1][2] = 1;
	b[1][1] = b[2][2] = 1;
	a[1][2] = a[2][1] = a[2][2] = 1;
	power(n - 1);
	muler();
	return 0;
}