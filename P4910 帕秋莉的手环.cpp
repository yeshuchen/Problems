#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int T;
struct matrix{
	int r, c;
	long long a[6][6];
	inline void init() {memset(a, 0, sizeof(a));}
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
}ans, mid;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		long long n;
		cin >> n;
		if(n == 1) {cout << 1 << '\n'; continue;}
		ans.init(); mid.init();
		ans.r = 1; ans.c = 4;
		ans.a[1][1] = ans.a[1][2] = ans.a[1][3] = 1;
		mid.a[1][1] = mid.a[2][1] = 1;
		mid.a[1][2] = 1;
		mid.a[3][3] = mid.a[4][3] = 1;
		mid.a[3][4] = 1; 
		matrix base; base.init();
		base.r = base.c = mid.r = mid.c = 4;
		for(int i = 1; i <= 4; i++)
			base.a[i][i] = 1;
		n -= 2;
		while(n)
		{
			if(n & 1) base = base * mid;
			mid = mid * mid;
			n >>= 1;
		}
		ans = ans * base;
		cout << (ans.a[1][1] + ans.a[1][2] + ans.a[1][3]) % mod << '\n';
	}
	return 0;
}
/*
d[1] JJ
d[2] JM
d[3] MJ
d[4] MM
*/