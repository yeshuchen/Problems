#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
struct matrix
{
	int r, c;
	long long a[4][4];
	inline void init()
	{
		r = c = 0; memset(a, 0, sizeof(a));
	}
	matrix operator * (const matrix &p)
	{
		matrix base;
		base.init();
		base.r = r; base.c = p.c;
		for(int i = 1; i <= r; i++)	
			for(int j = 1; j <= p.c; j++)
				for(int k = 1; k <= c; k++)
					base.a[i][j] = (base.a[i][j] + a[i][k] * p.a[k][j]) % mod;
		return base;
	}
};
matrix ans, mid, base;
int a1, a2, n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> a1 >> a2 >> n; n--;
	ans.r = 1; ans.c = 2; mid.r = mid.c = 2; base.r = base.c = 2;
	ans.a[1][1] = a1; ans.a[1][2] = a2; base.a[1][1] = base.a[2][2] = 1;
	mid.a[1][1] = 0; mid.a[2][1] = 1; mid.a[1][2] = -1; mid.a[2][2] = 1;
	while(n)
	{
		if(n & 1) base = base * mid;
		n >>= 1;
		mid = mid * mid;
	}
	cout << ((ans * base).a[1][1] + mod) % mod;
	return 0;
}