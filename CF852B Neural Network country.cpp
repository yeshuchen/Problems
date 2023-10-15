#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5, mod = 1e9 + 7;
int n, m, L;
struct mat {
	int a[105][105];
	mat () {memset(a, 0, sizeof(a));}
	mat operator * (const mat c)
	{
		mat t;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < m; j++)
				for(int k = 0; k < m; k++)
					t.a[i][j] = (t.a[i][j] + 1ll * a[i][k] * c.a[k][j]) % mod;
		return t;
	}
} ans, r;
int num[N];
mat qpow(mat a, int b)
{
	mat base; b = max(b, 0ll);
	for(int i = 0; i < m; i++) base.a[i][i] = 1;
	while(b)
	{
		if(b & 1) base = base * a;
		a = a * a;
		b >>= 1;
	}
	return base;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> L >> m;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		ans.a[0][x % m]++;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> num[i];
		for(int j = 0; j < m; j++)
			r.a[j][(j + num[i]) % m]++;
	}
	int ANS = 0;
	ans = ans * qpow(r, L - 2);
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		ANS += ans.a[0][((m - x - num[i]) % m + m) % m];
		ANS %= mod;
	}
	cout << ANS;
	return 0;
}