#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
struct matrix
{
	int r, c;
	long long a[4][4];
	inline void init() {r = c = 0; memset(a, 0, sizeof(a));}
	matrix operator * (const matrix &p)
	{
		matrix base; base.init();
		base.r = r; base.c = p.c;
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= p.c; j++)
				for(int k = 1; k <= c; k++)
					base.a[i][j] = (base.a[i][j] + a[i][k] * p.a[k][j]) % mod;
		return base;
	}
};
inline matrix power(matrix a, long long b)
{
	matrix base; base.init();
	base.r = base.c = 2; base.a[1][1] = base.a[2][2] = 1;
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
	long long n; matrix ans, mid; ans.init(); mid.init();
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	ans.r = 1; ans.c = 2; mid.r = mid.c = 2;
	ans.a[1][1] = ans.a[1][2] = 1;
	mid.a[1][1] = mid.a[1][2] = mid.a[2][1] = 1;
	if(n == 1) {cout << 1; return 0;}
	ans = ans * power(mid, n - 2);
	cout << ans.a[1][1];
	return 0;
}