#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 10;
const int mod = 998244353;
using namespace std;
int n, d, ans;
int p[1000005];
signed main()
{
	cin >> n >> d;
	p[0] = 1;
	for(int i = 1; i <= max(n, d); i++)
		p[i] = p[i - 1] * 2 % mod;
	for(int i = 0; i <= d; i++)
	{
		int j = d - i;
		if(max(i, j) >= n) continue;
		int root = p[n - max(i, j)] - 1;
		int l = p[max(0ll,i - 1)];
		int r = p[max(0ll, j - 1)];
		ans = (ans + 2 * root % mod * l % mod * r % mod) % mod;
	}
	cout << (ans + mod) % mod;
	return 0;
}
