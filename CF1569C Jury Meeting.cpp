#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int T, n;
int a[200005];
inline int power(int a, int b)
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
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int pos = 1, pos2 = 0, cnt = 0, ans = 1;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 2; i <= n; i++)
			ans = ans * i % mod;
		for(int i = 1; i <= n; i++)
			if(a[i] > a[pos])
				pos = i;
		for(int i = 1; i <= n; i++)
			if(a[i] == a[pos])
				cnt++;
		if(cnt >= 2) {cout << ans << '\n'; continue;}
		for(int i = 1; i <= n; i++)
		{
			if(i == pos) continue;
			if(a[i] > a[pos2])
				pos2 = i;
		}
		if(a[pos] - a[pos2] > 1) {cout << 0 << '\n'; continue;}
		cnt = 0;
		for(int i = 1; i <= n; i++)
			if(a[i] == a[pos2]) cnt++;
		cout << ans * cnt % mod * power(cnt + 1, 998244351) % mod << '\n';
	}
	return 0;
}