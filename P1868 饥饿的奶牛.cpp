#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
const int N = 2e7 + 5;
int n, f[N];
struct node{
	int l, r;
}a[N];
int maxn[N];
inline void change(int p, int l, int r, int d, int k)
{
	if(l == r)
	{
		maxn[p] = max(maxn[p], k);
		return;
	}
	int mid = l + r >> 1;
	if(d <= mid) change(ls, l, mid, d, k);
	else change(rs, mid + 1, r, d, k);
	maxn[p] = max(maxn[ls], maxn[rs]);
}
inline int query(int p, int l, int r, int L, int R)
{
	if(L > R) return 0;
	if(L <= l && r <= R) return maxn[p];
	int mid = l + r >> 1, val = INT_MIN;
	if(L <= mid) val = max(val, query(ls, l, mid, L, R));
	if(R > mid) val = max(val, query(rs, mid + 1, r, L, R));
	return val;
}
inline bool cmp(node x, node y){
	return x.l < y.l;
}
int P;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].l >> a[i].r, P = max(P, a[i].r);
	sort(a + 1, a + n + 1, cmp);
	int ans = INT_MIN;
	for(int i = 1; i <= n; i++)
	{
		f[i] = (a[i].r - a[i].l + 1) + query(1, 1, P, 1, a[i].l - 1);
		change(1, 1, P, a[i].r, f[i]);
		ans = max(ans, f[i]);
	}
	cout << ans;
	return 0;
}