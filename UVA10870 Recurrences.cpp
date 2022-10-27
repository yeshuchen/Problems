#include<bits/stdc++.h>
using namespace std;
int d, n, m;
struct matrix{
	int r, c;
	long long a[20][20];
	inline void init() {memset(a, 0, sizeof(a));}
	matrix operator * (const matrix &p)
	{
		matrix base; base.init();
		base.r = r; base.c = p.c;
		for(int i = 1; i <= r; i++)	
			for(int j = 1; j <= p.c; j++)
				for(int k = 1; k <= c; k++)
					base.a[i][j] = (base.a[i][j] + a[i][k] * p.a[k][j]) % m;
		return base;
	}
};
int a[20];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(cin >> d >> n >> m)
	{
		if(!d && !n && !m) break;
		matrix base; base.init();
		matrix ans, mid; mid.init();
		for(int i = 1; i <= d; i++) cin >> a[i];
		for(int i = 1; i <= d; i++) cin >> ans.a[1][i];
		ans.r = 1; ans.c = d;
		mid.r = d; mid.c = d;
		base.r = d; base.c = d;
		for(int i = 1; i <= d; i++)
			base.a[i][i] = 1;	
		for(int i = 1; i <= d; i++)
			for(int j = 1; j < d; j++)
				if(i - j == 1) mid.a[i][j] = 1;
		for(int i = 1; i <= d; i++)
			mid.a[i][d] = a[d - i + 1];
		n--;
		while(n)
		{
			if(n & 1) base = base * mid;
			mid = mid * mid;
			n >>= 1;
		}
		ans = ans * base;
		cout << ans.a[1][1] << '\n';
	} 
	return 0;
}