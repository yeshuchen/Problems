#include<bits/stdc++.h>
using namespace std;
long long p, q, a1, a2, n, m;
struct matrix
{
	int col, row;
	long long a[4][4];
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
inline matrix power(matrix a, int b)
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	matrix ans, mid; ans.init(); mid.init();
	ans.col = 2; ans.row = 1;
	cin >> p >> q >> a1 >> a2 >> n >> m;
	if(n == 1)
	{
		cout << a1;
		return 0;
	}
	ans.a[1][1] = a2; ans.a[1][2] = a1;
	mid.row = mid.col = 2;
	mid.a[1][1] = p; mid.a[2][1] = q; mid.a[1][2] = 1;
	cout << (ans * power(mid, n - 2)).a[1][1];
	return 0;
}