#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, m, w, a, b, c, d;
char s[N];
int rk[N], sa[N], oldrk[N], height[N];
int st[N][20], lg2[N];
inline void buildst()
{
	lg2[0] = -1;
	for(int i = 1; i <= n; i++) lg2[i] = lg2[i / 2] + 1; lg2[0] = 0;
	for(int i = 1; i <= n; i++) st[i][0] = height[i];
	for(int j = 1; j <= 18; j++)
		for(int i = 1; i + (1 << j) - 1 <= n; i++)
			st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
}
inline int query(int l, int r)
{
	if(l == r) return n - sa[l] + 1;
	l++; int k = lg2[r - l + 1];
	return min(st[l][k], st[r - (1 << k) + 1][k]); 
}
int rt[N << 4], ls[N << 4], rs[N << 4], sum[N << 4], ret;
inline int build(int root, int l, int r)
{
	root = ++ret;
	if(l == r) return root;
	int mid = l + r >> 1;
	ls[root] = build(ls[root], l, mid);
	rs[root] = build(rs[root], mid + 1, r);
	return root;
}
inline int change(int root, int l, int r, int d)
{
	int nrt = ++ret;
	sum[nrt] = sum[root] + 1;
	if(l == r) return nrt;
	int mid = l + r >> 1; ls[nrt] = ls[root]; rs[nrt] = rs[root];
	if(d <= mid) ls[nrt] = change(ls[root], l, mid, d);
	else rs[nrt] = change(rs[root], mid + 1, r, d);
	return nrt;
}
inline int find(int lrt, int rrt, int l, int r, int L, int R)
{
	if(L <= l && r <= R) return sum[rrt] - sum[lrt];
	int mid = l + r >> 1, val = 0;
	if(L <= mid) val += find(ls[lrt], ls[rrt], l, mid, L, R);
	if(R > mid) val += find(rs[lrt], rs[rrt], mid + 1, r, L, R);
	return val;
}
inline bool check(int len)
{
	int p = rk[c];
	int l = 1, r = p, L = 0, R = 0;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(query(mid, p) >= len) r = (L = mid) - 1;
		else l = mid + 1;
	}
	l = p, r = n;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(query(p, mid) >= len) l = (R = mid) + 1;
		else r = mid - 1;
	}
	return find(rt[L - 1], rt[R], 1, n, a, b - len + 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> s[i], rk[i] = s[i], sa[i] = i;
	for(w = 1; w < n; w <<= 1)
	{
		sort(sa + 1, sa + n + 1, [](int x, int y) {
			return rk[x] == rk[y] ? rk[x + w] < rk[y + w] : rk[x] < rk[y];
		});
		memcpy(oldrk + 1, rk + 1, n * sizeof(int));
		for(int i = 1, p = 0; i <= n; i++)
		{
			if(oldrk[sa[i]] == oldrk[sa[i - 1]] && oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) rk[sa[i]] = p;
			else rk[sa[i]] = ++p;
		}
	}
	int k = 0;
	for(int i = 1; i <= n; i++)
	{
		if(k) k--;
		int j = sa[rk[i] - 1];
		while(i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
		height[rk[i]] = k;
	}
	buildst();
	rt[0] = build(rt[0], 1, n);
	for(int i = 1; i <= n; i++)
		rt[i] = change(rt[i - 1], 1, n, sa[i]);
	while(m--)
	{
		int l, r, ans = 0;
		cin >> a >> b >> c >> d;
		l = 1; r = min(b - a + 1, d - c + 1);
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(check(mid)) l = (ans = mid) + 1;
			else r = mid - 1;
		}
		cout << ans << '\n';
	}
	return 0;
}