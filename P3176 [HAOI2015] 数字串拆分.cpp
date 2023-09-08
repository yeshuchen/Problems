#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, m;
struct mat {
	int a[6][6];
	mat operator * (const mat &t)
	{
		mat c; memset(c.a, 0, sizeof(c.a));
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= m; j++)
				for(int k = 1; k <= m; k++)
					c.a[i][j] = (c.a[i][j] + a[i][k] * t.a[k][j]) % mod;
		return c;
	}
	mat operator + (const mat &t)
	{
		mat c; memset(c.a, 0, sizeof(c.a));
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= m; j++)
				c.a[i][j] = (a[i][j] + t.a[i][j]) % mod;
		return c;
	}
} p[15], d[505][505], g[505];
char s[505];
inline mat pow_10(mat k)
{
	k = k * k; mat ret = k;
	k = k * k; k = k * k; ret = ret * k;
	return ret;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s + 1 >> m;
	n = strlen(s + 1);
	for(int i = 1; i <= m; i++) p[1].a[i][m] = g[0].a[i][i] = 1;
	for(int i = 2; i <= m; i++) p[1].a[i][i - 1] = 1;
	for(int i = 2; i < 10; i++) p[i] = p[i - 1] * p[1];
	for(int i = 1; i <= n; i++)
	{
		mat res; memset(res.a, 0, sizeof(res.a));
		for(int j = 1; j <= m; j++) res.a[j][j] = 1;
		for(int j = i; j <= n; j++)
		{
			res = pow_10(res);
			if(s[j] > '0') res = res * p[s[j] - '0'];
			d[i][j] = res;
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < i; j++)
			g[i] = g[i] + g[j] * d[j + 1][i];
	int ans = 0;
	for(int i = 1; i <= m; i++)
		ans = (ans + g[n].a[1][i]) % mod;	
	cout << ans;
	return 0;
}