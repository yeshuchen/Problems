#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct matrix {
	int r, c;
	ll a[4][4];
	inline void init() {memset(a, 0, sizeof(a));}
} base, ans, bc;
ll n, a, b, c, mod;
inline ll qmul(ll a, ll b)
{
	ll base = 0;
	while(b)
	{
		if(b & 1) base = (base + a) % mod;
		a = a * 2 % mod;
		b >>= 1;
	}
	return base;
}
matrix operator * (const matrix &a, const matrix &b) {
	matrix c;
	c.init(); c.r = a.r; c.c = b.c;
	for(int i = 1; i <= a.r; i++)
		for(int j = 1; j <= b.c; j++)
			for(int k = 1; k <= a.c; k++)
				c.a[i][j] = (c.a[i][j] + qmul(a.a[i][k], b.a[k][j])) % mod;
	return c;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> a >> b >> c >> mod;
	ans.r = 1; ans.c = 3; bc.r = bc.c = 3; base.r = base.c = 3;
	ans.a[1][1] = 1; ans.a[1][2] = b; ans.a[1][3] = c;
	for(int i = 1; i <= 3; i++) base.a[i][i] = 1;
	bc.a[1][1] = a + b; bc.a[2][1] = 1; bc.a[3][1] = 1;
	bc.a[2][2] = a + b; bc.a[3][3] = 1;
	n--;
	while(n)
	{
		if(n & 1) base = base * bc;
		bc = bc * bc;
		n >>= 1;
	}
	cout << (ans * base).a[1][1];
	return 0;
}