#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int T, n;
int a[N], l[N], c[N];
inline int query(int x)
{
	int mx = 0;
	while(x)
		mx = max(mx, c[x]), x -= (x & -x);
	return mx;
}
inline void add(int x, int v)
{
	for(int i = x; i <= n; i += (i & -i))
		c[i] = max(c[i], v);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i], c[i] = 0;
		for(int i = 1; i <= n; i++)
		{
			l[i] = query(a[i]) + 1;
			add(a[i], l[i]);
		}
		for(int i = 1; i <= n; i++) ans += (l[i] == 2);
		cout << ans << '\n';
	}
	return 0;
}