#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, q, tot;
int p[200005];
ll f[2000005];
struct node{
	ll w, l;
} a[200005], b[200005], stk[200005];
inline bool cmp(node x, node y) {return (x.w == y.w ? x.l > y.l : x.w > y.w);}
inline double getk(node x, node y) {return 1.0 * (x.l - y.l) / (x.w - y.w);}
inline void update(ll x, ll y, int id)
{
	node t = (node){x, y};
	while(tot >= 2 && getk(stk[tot], t) >= getk(stk[tot - 1], t)) tot--;
	stk[++tot] = t; p[tot] = id;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].w >> a[i].l;
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1, mx = 0; i <= n; i++)
		if(a[i].l > mx)
			mx = a[i].l, b[++q] = a[i];
	for(int i = 1; i <= q; i++)
	{
		update(b[i].w, f[i - 1], i);
		int l = 2, r = tot, res = 1;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(getk(stk[mid], stk[mid - 1]) >= -b[i].l) l = (res = mid) + 1;
			else r = mid - 1;
		}
		f[i] = f[p[res] - 1] + 1ll * b[i].l * b[p[res]].w;
	}
	cout << f[q];
	return 0;
}