#include<bits/stdc++.h>
#define ll __int128
using namespace std;
long long p, q, a0, g, n, m;
struct matrix
{
	int col, row;
	ll a[4][4];
	inline void init()
	{
		col = row = 0;
		memset(a, 0, sizeof(a));
	}
	matrix operator * (const matrix &p)
	{
		matrix base; base.init();
		base.row = row; base.col = p.col;
		for(int i = 1; i <= row; i++)
			for(int j = 1; j <= p.col; j++)
				for(int k = 1; k <= p.row; k++)
					base.a[i][j] = (base.a[i][j] + a[i][k] * p.a[k][j]) % m;
		return base;
	}
};
inline matrix power(matrix a, long long b)
{
	matrix base; base.init();
	base.col = base.row = 2;
	base.a[1][1] = base.a[2][2] = 1;
	while(b)
	{
		if(b & 1) base = base * a;
		b >>= 1;
		a = a * a;
	}
	return base;
}
inline void write(__int128 x)
{
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	matrix ans, mid; ans.init(); mid.init();
	ans.col = 2; ans.row = 1;
	cin >> m >> p >> q >> a0 >> n >> g;
	ans.a[1][1] = a0; ans.a[1][2] = 1;
	mid.row = mid.col = 2;
	mid.a[1][1] = p; mid.a[2][1] = q; mid.a[2][2] = 1;
	write((ans * power(mid, n)).a[1][1] % g);
	return 0;
}