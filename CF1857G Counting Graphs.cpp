#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5, mod = 998244353;
int T, n, m;
struct node {
	int x, y, z;
} e[N];
inline bool cmp(node x, node y) {
	return x.z < y.z;
}
inline int qpow(int a, int b)
{
	int base = 1;
	while(b)
	{
		if(b & 1) base = base * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return base;
}
int f[N], sz[N];
inline int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		int ans = 1;
		for(int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
		for(int i = 1; i < n; i++)
			cin >> e[i].x >> e[i].y >> e[i].z;
		sort(e + 1, e + n, cmp);
		for(int i = 1; i < n; i++)
		{
			if(e[i].z == m) break;
			int x = find(e[i].x), y = find(e[i].y);
			// cout << x << ' ' << y << '\n' << sz[x] << ' ' << sz[y] << '\n' << "ngm\n";
			ans *= qpow(m - e[i].z + 1, sz[x] * sz[y] - 1);
			ans %= mod;
			sz[x] += sz[y]; f[y] = x;
		}
		cout << ans << '\n';
	}
	return 0;
}