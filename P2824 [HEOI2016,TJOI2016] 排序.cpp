#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
const int N = 2e5 + 5;
int n, m, q;
int sum[N << 2], t[N << 2], tag[N << 2];
inline void build(int p, int l, int r)
{
	tag[p] = -1;
	if(l == r) {sum[p] = t[l]; return;}
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	sum[p] = sum[ls] + sum[rs];
}
inline void pushdown(int p, int l, int r)
{
	if(tag[p] == -1) return;
	int mid = l + r >> 1;
	sum[ls] = (mid - l + 1) * tag[p];
	sum[rs] = (r - mid) * tag[p];
	tag[ls] = tag[rs] = tag[p];
	tag[p] = -1;
}
inline int ask(int p, int l, int r, int L, int R)
{
	if(L <= l && r <= R) return sum[p];
	int mid = l + r >> 1, val = 0; pushdown(p, l, r);
	if(L <= mid) val += ask(ls, l, mid, L, R);
	if(R > mid) val += ask(rs, mid + 1, r, L, R);
	return val;
}
inline void change(int p, int l, int r, int L, int R, int op)
{
	if(L > R) return;
	if(L <= l && r <= R)
	{
		sum[p] = (r - l + 1) * op;
		tag[p] = op;
		return;
	}
	int mid = l + r >> 1; pushdown(p, l, r);
	if(L <= mid) change(ls, l, mid, L, R, op);
	if(R > mid) change(rs, mid + 1, r, L, R, op);
	sum[p] = sum[ls] + sum[rs];
}
int a[N], op[N], l[N], r[N];
inline bool check(int w)
{
	for(int i = 1; i <= n; i++)
		t[i] = (a[i] >= w);
	build(1, 1, n);
	for(int i = 1; i <= m; i++)
	{
		int cnt = r[i] - l[i] + 1 - ask(1, 1, n, l[i], r[i]);
		if(op[i]) cnt = (r[i] - l[i] + 1 - cnt);
		change(1, 1, n, l[i], l[i] + cnt - 1, op[i]);
		change(1, 1, n, l[i] + cnt, r[i], op[i] ^ 1);
	}
	return ask(1, 1, n, q, q);
}
int L = 1, R, ans = 1;
int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i], R = max(R, a[i]);
	for(int i = 1; i <= m; i++) cin >> op[i] >> l[i] >> r[i];
	cin >> q;
	while(L <= R)
	{
		int mid = L + R >> 1;
		if(check(mid)) L = (ans = mid) + 1;
		else R = mid - 1;
	}
	cout << ans;
	return 0;
}