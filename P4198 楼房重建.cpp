#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
const int N = 2e5 + 5;
int n, m;
int ans[N << 2];
double mx[N << 2];
inline int update(int p, int l, int r, double maxn)
{
	int mid = l + r >> 1;
	if(mx[p] <= maxn) return 0;
	if(l == r) return mx[p] > maxn;
	if(mx[ls] <= maxn) return update(rs, mid + 1, r, maxn);
	return update(ls, l, mid, maxn) + ans[p] - ans[ls];
}
inline void change(int p, int l, int r, int x, int y)
{
	if(l == r)
	{
		ans[p] = 1;
		mx[p] = 1.0 * y / x;
		return;
	}
	int mid = l + r >> 1;
	if(x <= mid) change(ls, l, mid, x, y);
	else change(rs, mid + 1, r, x, y);
	mx[p] = max(mx[ls], mx[rs]);
	ans[p] = ans[ls] + update(rs, mid + 1, r, mx[ls]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		change(1, 1, n, x, y);
		cout << ans[1] << '\n';
	}
	return 0;
}