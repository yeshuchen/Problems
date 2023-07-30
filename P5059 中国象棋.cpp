#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, mod;
struct mat
{
	int r, c;
	ll a[5][5];
	inline void init() {memset(a, 0, sizeof(a));}
	mat operator * (const mat &f)
	{
		mat d; d.init();
		d.r = r; d.c = f.c;
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= d.c; j++)
				for(int k = 1; k <= c; k++)
					d.a[i][j] = (d.a[i][j] + (__int128)(a[i][k]) * f.a[k][j] % mod) % mod;
		return d;
	}
} ans, base, bc;
inline ll power(ll a, ll b)
{
	ll bs = 1;
	while(b)
	{
		if(b & 1) bs = (__int128)bs * a % mod;
		a = (__int128)a * a % mod;
		b >>= 1;
	}
	return bs;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> mod;
	bc.init(); ans.init(); base.init();
	ans.r = 1; ans.c = 2;
	ans.a[1][1] = 2; ans.a[1][2] = 3;
	base.r = base.c = 2;
	base.a[1][1] = base.a[2][2] = 1;
	bc.r = bc.c = 2;
	bc.a[2][1] = bc.a[1][2] = bc.a[2][2] = 1;
	ll tmp = n + 1;
	while(n)
	{
		if(n & 1) base = base * bc;
		bc = bc * bc;
		n >>= 1;
	}
	// cout << (ans * base).a[1][1] - tmp - 1 << '\n';
	cout << power((((ans * base).a[1][1] - tmp - 1) % mod + mod) % mod, tmp);
	return 0;
}