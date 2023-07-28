#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e7 + 7;
ll n;
bool v[55];
ll f[55][55], ans[55];
inline ll qpow(ll a, ll b)
{
	ll base = 1;
	while(b)
	{
		if(b & 1) base = base * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return base;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	f[0][0] = 1;
	for(int i = 1; i <= 50; i++)
	{
		f[i][0] = f[i - 1][0];
		for(int j = 1; j <= i; j++)
			f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
	}
	for(int i = 0; i <= 50; i++)
		v[i] = (bool)(n & (1ll << i));
	int res = 0;
	for(int i = 50; i >= 0; i--)
	{
		if(v[i])
		{
			res++;
			ans[res]++;
			if(i < 1) continue;
			for(int j = 1; j <= i; j++)
				ans[j + res - 1] += f[i][j];
		}
	}	
	ll s = 1;
	for(int i = 1; i <= 50; i++)
		s = s * qpow(i, ans[i]) % mod;
	cout << s;
	return 0;
}