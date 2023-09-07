#include<bits/stdc++.h>
using namespace std;
long long n, mod, k, pos;
struct mat {
	int r, c;
	long long v[55][55];
	mat operator * (const mat &a) const {
		mat c; c.r = r; c.c = a.c;
		memset(c.v, 0, sizeof(c.v));
		for(int i = 1; i <= c.r; i++)
			for(int j = 1; j <= c.c; j++)
				for(int k = 1; k <= a.r; k++)
					c.v[i][j] = (c.v[i][j] + v[i][k] * a.v[k][j]) % mod;
		return c;
	}
} base, tmp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> mod >> k >> pos;
	base.r = base.c = k; tmp.r = tmp.c = k;
	for(int i = 1; i <= k; i++)
		base.v[i][i] = 1;
	for(int i = 1; i <= k; i++)
	{
		if(i == 1) tmp.v[k][i] = 1;
		else tmp.v[i - 1][i] = 1;
		tmp.v[i][i] = 1;
	}
	if(k == 1) tmp.v[1][1] = 2;
	// for(int i = 1; i <= k; i++, cout << '\n')
	// 	for(int j = 1; j <= k; j++)
	// 		cout << tmp.v[i][j] << ' ';
	n *= k;
	while(n)
	{
		if(n & 1) base = base * tmp;
		tmp = tmp * tmp;
		n >>= 1;
	}
	tmp.r = 1; tmp.c = k;
	memset(tmp.v, 0, sizeof(tmp.v));
	tmp.v[1][1] = 1;
	tmp = tmp * base;
	cout << tmp.v[1][pos + 1];
	return 0;
}