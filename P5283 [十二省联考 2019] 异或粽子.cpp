#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k;
int a[N];
struct node {
	int val, l, r, pl, pr;
};
int cnt, rt[N], ed[N << 5];
int ls[N << 5], rs[N << 5], sum[N << 5];
bool operator < (const node &a, const node &b) {return a.val < b.val;}
priority_queue<node> q;
inline int insert(int root, int x, int id, int d)
{
	int nrt = ++cnt;
	sum[nrt] = sum[root] + 1; ed[nrt] = ed[root];
	ls[nrt] = ls[root]; rs[nrt] = rs[root];
	if(d == -1) {ed[nrt] = id; return nrt;}
	if(x & (1ll << d)) ls[nrt] = insert(ls[root], x - (1ll << d), id, d - 1);
	else rs[nrt] = insert(rs[root], x, id, d - 1);
	return nrt;
}
inline int query(int rt1, int rt2, int x, int d)
{
	if(d == -1) return ed[rt1];
	bool f = (x & (1ll << d));
	if(f)
	{
		if(sum[rs[rt1]] - sum[rs[rt2]] > 0) return query(rs[rt1], rs[rt2], x, d - 1);
		else return query(ls[rt1], ls[rt2], x, d - 1);
	}
	else
	{
		if(sum[ls[rt1]] - sum[ls[rt2]] > 0) return query(ls[rt1], ls[rt2], x, d - 1);
		else return query(rs[rt1], rs[rt2], x, d - 1);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	a[1] = 0; n++;
	rt[1] = insert(rt[0], a[1], 1, 31);
	for(int i = 2; i <= n; i++) cin >> a[i], a[i] ^= a[i - 1], rt[i] = insert(rt[i - 1], a[i], i, 31);
	for(int i = 2; i <= n; i++)
	{
		int j = query(rt[i], rt[0], a[i], 31);
		q.push({a[i] ^ a[j], 1, i - 1, j, i});
	}
	int ans = 0;
	for(int i = 1; i <= k; i++)
	{
		node x = q.top(); q.pop();
		ans += x.val; int j;
		if(x.l < x.pl)
		{
			j = query(rt[x.pl - 1], rt[x.l - 1], a[x.pr], 31);
			q.push({a[x.pr] ^ a[j], x.l, x.pl - 1, j, x.pr});
		}
		if(x.r > x.pl)
		{
			j = query(rt[x.r], rt[x.pl], a[x.pr], 31);
			q.push({a[x.pr] ^ a[j], x.pl + 1, x.r, j, x.pr});
		}
	}
	cout << ans;
	return 0;
}