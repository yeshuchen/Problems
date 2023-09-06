#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m;
struct node {
	int x, t;
} a[N];
struct BIT {
	int c[N], n;
	inline void add(int x, int v)
	{
		while(x <= n)
			c[x] += v, x += (x & -x);
	}
} t1, t2;
int tmp[N];
inline int solve(int up)
{
	int res = 0, cnt = 0, p = 0;
	for(int i = 18; i >= 0; i--)
		if(p + (1 << i) <= t1.n && res + t1.c[p + (1 << i)] <= up)
		{
			p += (1 << i);
			res += t1.c[p];
			cnt += t2.c[p]; 
		}
	return cnt;
}
signed main()
{
	int ans = 0;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].t, tmp[i] = a[i].t;
	sort(a + 1, a + n + 1, [](node x, node y) {
		return x.x < y.x;
	});
	sort(tmp + 1, tmp + n + 1);
	int cnt = unique(tmp + 1, tmp + n + 1) - tmp - 1;
	t1.n = t2.n = cnt;
	for(int i = 1; i <= n; i++)
	{
		a[i].t = lower_bound(tmp + 1, tmp + cnt + 1, a[i].t) - tmp;
		t1.add(a[i].t, tmp[a[i].t]);
		t2.add(a[i].t, 1);
		ans = max(ans, solve(m - a[i].x));
	}
	cout << ans;
	return 0;
}