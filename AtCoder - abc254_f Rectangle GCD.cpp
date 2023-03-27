#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m;
int a[N], b[N], d[N];
struct SegmentTree{
	#define ls (p << 1)
	#define rs (p << 1 | 1)
	int gcd[N];
	inline void build(int p, int l, int r)
	{
		if(l > r) return;
		if(l == r)
		{
			gcd[p] = d[l];
			return;
		}
		int mid = l + r >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		if(gcd[ls] == 0 && gcd[rs] == 0) gcd[p] = 0;
		else if(gcd[ls] == 0) gcd[p] = gcd[rs];
		else if(gcd[rs] == 0) gcd[p] = gcd[ls];
		else gcd[p] = __gcd(gcd[ls], gcd[rs]);
	}
	inline int ask(int p, int l, int r, int L, int R, int w)
	{
		if(L > R) return 0;
		if(L <= l && r <= R) return gcd[p];
		int mid = l + r >> 1, val = w;
		if(L <= mid) val = __gcd(ask(ls, l, mid, L, R, w), val);
		if(R > mid) val = __gcd(ask(rs, mid + 1, r, L, R, w), val);
		return val;
	}
}s[2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < n; i++) d[i] = abs(a[i] - a[i + 1]);
	s[0].build(1, 1, n - 1);
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i < n; i++) d[i] = abs(b[i] - b[i + 1]);
	s[1].build(1, 1, n - 1);
	for(int i = 1; i <= m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> x2 >> y1 >> y2;
		cout << __gcd(s[0].ask(1, 1, n - 1, x1, x2 - 1, a[x1] + b[y1]), __gcd(s[1].ask(1, 1, n - 1, y1, y2 - 1, a[x1] + b[y1]), a[x1] + b[y1])) << '\n';
	}
	return 0;
}