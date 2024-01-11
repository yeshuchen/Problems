#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, m, mod;
int f[N], sz[N];
int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
int ksm(int a, int b)
{
	int base = 1;
	while(b)
	{
		if(b & 1) base = 1ll * base * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return base;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> mod;
	int cnt = n;
	for(int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		int fx = find(x), fy = find(y);
		if(fx == fy) continue;
		cnt--; f[fy] = fx; sz[fx] += sz[fy];
	}
	if(cnt == 1) {cout << 1 % mod; return 0;}
	int ans = 1;
	for(int i = 1; i <= n; i++)
		if(find(i) == i)
			ans = 1ll * ans * sz[i] % mod;
	ans = 1ll * ans * ksm(n, cnt - 2) % mod;
	cout << ans;
	return 0;
}