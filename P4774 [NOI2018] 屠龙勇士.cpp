#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int T, n, m, x, y;
int a[N], b[N], p[N], sd[N];
int exgcd(int a, int b)
{
	if(a % b == 0) return x = 0, y = 1, b;
	int g = exgcd(b, a % b), z = x;
	x = y; y = z - a / b * y;
	return g;
}
int exCRT()
{
	__int128 MOD = 1, ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int g = exgcd(b[i] * MOD, p[i]);
		int X = (a[i] - (__int128)b[i] * ans % p[i]) % p[i] + p[i], Y = p[i];
		if(X % g) return -1;
		X /= g; Y /= g;
		ans += (__int128)x * X % Y * MOD;
		MOD *= Y; ans %= MOD;
	}
	for(int i = 1; i <= n; i++)
	{
		int w = a[i] - ans * b[i];
		if(w <= 0) continue;
		ans += ((w - 1) / (b[i] * MOD) + 1) * MOD;
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		multiset<int> s;
		cin >> n >> m;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) cin >> p[i];
		for(int i = 1; i <= n; i++) cin >> sd[i];
		for(int i = 1, x; i <= m; i++) cin >> x, s.insert(x);
		for(int i = 1; i <= n; i++)
		{
			auto it = s.upper_bound(a[i]);
			if(it != s.begin()) it--;
			b[i] = *it;
			s.erase(it); s.insert(sd[i]);
		}
		cout << exCRT() << '\n';
	}
	return 0;
}