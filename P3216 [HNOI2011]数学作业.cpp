#include<bits/stdc++.h>
#define ll __int128
using namespace std;
long long n, mod;
struct matrix
{
	ll row, col;
	ll m[4][4];
	inline void init()
	{
		row = 0; col = 0;
		memset(m, 0, sizeof(m));
	}
	matrix operator *(const matrix &a)
	{
		matrix base;
		base.init();
		base.row = row; base.col = a.col;
		for(int i = 1; i <= base.row; i++)
			for(int j = 1; j <= base.col; j++)
				for(int k = 1; k <= col; k++)
					base.m[i][j] = (base.m[i][j] + m[i][k] * a.m[k][j]) % mod;
		return base;
	}
};
inline matrix power(matrix a, ll b)
{
	matrix base;
	base.init();
	base.row = base.col = 3;
	base.m[1][1] = base.m[2][2] = base.m[3][3] = 1;
	while(b)
	{
		if(b & 1) base = base * a;
		b >>= 1;
		a = a * a;
	}
	return base;
}
inline int c(ll x)
{
	int res = 0;
	while(x) x /= 10, res++;
	return res;
}
inline void write(__int128 ans)
{
	if(ans > 9) write(ans / 10);
	putchar(ans % 10 + 48);
}
ll len, POW[19];
matrix ans, mid;
int main()
{
	cin >> n >> mod;
	POW[0] = 1;
	for(int i = 1; i <= 18; i++) POW[i] = POW[i - 1] * 10;
	ll length = c(n);
	len = n - POW[length - 1];
	ans.row = 1; ans.col = 3; mid.row = mid.col = 3;
	mid.m[2][1] = mid.m[2][2] = mid.m[3][1] = mid.m[3][2] = mid.m[3][3] = 1;
	for(int i = 1; i <= length; i++)
	{
		ans.m[1][1] = (ans.m[1][1] * POW[i] + POW[i - 1]) % mod; ans.m[1][2] = POW[i - 1]; ans.m[1][3] = 1;
		mid.m[1][1] = POW[i];
		ll num = POW[i - 1] * 9 - 1;
		if(i == length) num = len;
		ans = ans * power(mid, num);
	}
	write(ans.m[1][1]);
	return 0;
}