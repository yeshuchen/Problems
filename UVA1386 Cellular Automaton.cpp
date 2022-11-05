#include<bits/stdc++.h>
using namespace std;
long long n, m, d, k;
struct matrix{
	int r, c;
	long long a[505][505];
	inline void init() {memset(a, 0, sizeof(a));}
	matrix operator * (const matrix &p)
	{
		matrix base; base.init();
		base.r = r; base.c = p.c;
		for(int i = 1; i <= p.c; i++)
			for(int k = 1; k <= c; k++)
				base.a[1][i] = (base.a[1][i] + a[1][k] * p.a[k][i]) % m;
		for(int i = 2; i <= r; i++)
			for(int j = 1; j <= p.c; j++)
				base.a[i][j] = base.a[i - 1][(j == 1) ? n : j - 1];
		return base;
	}
};
inline int move(int s, int k)
{
	s += k;
	if(s > n) s = 1;
	if(s < 1) s = n;
	return s;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(cin >> n >> m >> d >> k)
	{
		matrix base; base.init(); base.r = base.c = n;
		matrix ans, mid; ans.init(); mid.init();
		ans.r = 1; ans.c = n; mid.r = mid.c = n;
		for(int i = 1; i <= n; i++) cin >> ans.a[1][i], base.a[i][i] = 1;
		for(int j = 1; j <= n; j++)
		{
			int p1 = j, p2 = j;
            mid.a[j][j] = 1;
			for(int i = 1; i <= d; i++)
				p1 = move(p1, 1), mid.a[p1][j] = 1;
			for(int i = 1; i <= d; i++)
				p2 = move(p2, -1), mid.a[p2][j] = 1;
		}
		while(k)
		{
			if(k & 1) base = base * mid;
			k >>= 1;
			mid = mid * mid;
		}
		ans = ans * base;
		cout << ans.a[1][1];
		for(int i = 2; i <= n; i++) cout << ' ' << ans.a[1][i]; 
		cout << '\n';
	}
	return 0;
}