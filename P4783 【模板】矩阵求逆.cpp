#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7, N = 405;
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
int n, a[N][N], b[N][N];
void guass()
{
	for(int i = 1; i <= n; i++)
	{
		int p = -1;
		for(int j = i; j <= n; j++)
			if(a[j][i]) {p = j; break;}
		if(!~p) {cout << "No Solution"; exit(0);}
		swap(a[p], a[i]); swap(b[p], b[i]);
		int inv = ksm(a[i][i], mod - 2);
		for(int j = 1; j <= n; j++) a[i][j] = a[i][j] * inv % mod, b[i][j] = b[i][j] * inv % mod;
		for(int j = 1; j <= n; j++)
		{
			if(j == i) continue;
			int q = a[j][i];
			for(int k = 1; k <= n; k++)
			{
				a[j][k] = (a[j][k] - q * a[i][k] % mod + mod) % mod;
				b[j][k] = (b[j][k] - q * b[i][k] % mod + mod) % mod;
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j], b[i][j] = (i == j);
	guass();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cout << b[i][j] << (j == n ? '\n' : ' ');
	return 0;
}