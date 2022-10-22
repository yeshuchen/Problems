#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int T;
long long a[N], s[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		cout << "Case " << i << ':' << '\n';
		int n, q;
		long long ans = 0;
		cin >> n >> q;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
		for(int i = 1; i <= n; i++) ans += (n - i) * a[i] - (s[n] - s[i]);
		for(int i = 1; i <= q; i++)
		{
			long long op, x, v;
			cin >> op;
			if(op == 1) {cout << ans << '\n'; continue;}
			cin >> x >> v; x++;
			ans += (x - 1) * (a[x] - v) - (n - x) * (a[x] - v);
			a[x] = v;
		}
	}
	return 0;
}