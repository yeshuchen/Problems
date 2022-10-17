#include<bits/stdc++.h>
#define ll __int128
using namespace std;
long long n, m;
int p, q, r, t, u, v, w, x, y, z;
struct matrix
{
	int col, row;
	ll a[13][13] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, p, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
					{0, 1, u, 1, 0, 1, 0, 0, 0, 0, 0, 0},
					{0, 1, 1, x, 0, 0, 1, 0, 0, 0, 0, 0},
					{0, q, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, v, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, y, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, r, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
					{0, t, 0, 1, 0, 0, 0, 2, 1, 0, 0, 0},
					{0, 1, 0, 2, 0, 0, 0, 1, 1, 1, 0, 0},
					{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, w, 0},
					{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, z}};
	inline void init()
	{
		col = row = 0;
		memset(a, 0, sizeof(a));
	}
	matrix operator *(const matrix & p)
	{
		matrix base;
		base.init();	
		base.row = row; base.col = col;
		for(int i = 1; i <= base.row; i++)
			for(int j = 1; j <= base.col; j++)
				for(int k = 1; k <= p.row; k++)
					base.a[i][j] = (base.a[i][j] + a[i][k] * p.a[k][j]) % m;
		return base;
	}
};
inline matrix power(matrix a, ll b)
{
	matrix base; base.init(); base.row = base.col = 11;
	for(int i = 1; i <= 11; i++) base.a[i][i] = 1;
	while(b)
	{
		if(b & 1) base = base * a;
		b >>= 1;
		a = a * a;
	}
	return base;
}
inline void write(ll w)
{
	if(w > 9) write(w / 10);
	putchar(w % 10 + 48);
}
int main()
{
	cin >> n >> m >> p >> q >> r >> t >> u >> v >> w >> x >> y >> z;
	matrix ans, mid; ans.init();
	ans.row = 1; ans.col = 11;
	ans.a[1][1] = ans.a[1][2] = ans.a[1][3] = 3; ans.a[1][4] = ans.a[1][5] = ans.a[1][6] = 1; ans.a[1][7] = ans.a[1][8] = ans.a[1][9] = 1; ans.a[1][10] = w; ans.a[1][11] = z;
	mid.row = mid.col = 11;
	mid = power(mid, n - 2);
	ans = ans * mid;
	cout << "nodgd" << ' '; write(ans.a[1][1]); cout << '\n';
	cout << "Ciocio" << ' '; write(ans.a[1][2]); cout << '\n';
	cout << "Nicole" << ' '; write(ans.a[1][3]);
	return 0;
}