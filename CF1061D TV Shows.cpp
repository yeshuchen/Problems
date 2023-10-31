#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5, mod = 1e9 + 7;
int n, x, y;
struct node {
	int l, r;
} a[N];
int ans = 0;
multiset<int, greater<int> > s;
bool cmp(node x, node y) {return x.l < y.l;}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> x >> y;
	for(int i = 1; i <= n; i++)
		cin >> a[i].l >> a[i].r;
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++)
	{
		auto it = s.upper_bound(a[i].l);
		// cout << a[i].l << ' ' << *it << '\n';
		int res = x + y * (a[i].r - a[i].l);
		if(it != s.end())
		{
			res = min(res, y * (a[i].r - *it));
			s.erase(it);
		}
		ans += res; ans %= mod;
		s.insert(a[i].r);
	}
	cout << ans;
	return 0;
}