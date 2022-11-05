#include<bits/stdc++.h>
using namespace std;
struct matrix{
	int r, c;
	long long a[4][4];
	inline void init() {memset(a, 0, sizeof(a));}
	matrix operator * (const matrix &p)
	{
		matrix base;
		base.init();
		base.r = r; base.c = p.c;
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= p.c; j++)
				for(int k = 1; k <= c; k++)
					base.a[i][j] += a[i][k] * p.a[k][j];
		return base;
	}
};
int x, y, n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(cin >> x >> y >> n)
	{
		matrix ans, mid, base; ans.init(); mid.init(); base.init();
		base.r = base.c = 2;
		ans.r = 1; ans.c = 2; mid.r = mid.c = 2; base.a[1][1] = base.a[2][2] = 1;
		ans.a[1][1] = 2; ans.a[1][2] = x; mid.a[2][1] = 1; mid.a[1][2] = -y; mid.a[2][2] = x;
		while(n)
		{
			if(n & 1) base = base * mid;
			n >>= 1;
			mid = mid * mid;
		}
		cout << (ans * base).a[1][1] << '\n';
	}
	return 0;
}