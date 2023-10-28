#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m;
int a[N];
struct query {
	int l, r, id;
} q[N];
int lp[N], rp[N], in[N], tem[N], ans[N];
int CNTl[N], CNTr[N];
int ret, cntl[N], cntr[N];
bool cmp(query x, query y) {return in[x.l] == in[y.l] ? x.r < y.r : in[x.l] < in[y.l];}
int bf(int L, int R)
{
	int res = 0;
	for(int i = L; i <= R; i++)
		CNTl[a[i]] = -1, CNTr[a[i]] = 0;
	for(int i = L; i <= R; i++)
	{
		CNTr[a[i]] = i;
		if(!~CNTl[a[i]]) CNTl[a[i]] = i; 
		res = max(res, CNTr[a[i]] - CNTl[a[i]]);
	}
	return res;
}
void add(int x)
{
	if(!~cntl[a[x]]) cntl[a[x]] = x;
	cntr[a[x]] = max(cntr[a[x]], x);
	ret = max(ret, cntr[a[x]] - cntl[a[x]]);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; int sz = sqrt(n);
	for(int i = 1; i <= n; i++) cin >> a[i], tem[i] = a[i];
	sort(tem + 1, tem + n + 1);
	int tot = unique(tem + 1, tem + n + 1) - tem - 1;
	for(int i = 1; i <= n; i++)
		a[i] = lower_bound(tem + 1, tem + tot + 1, a[i]) - tem;
	for(int i = 1; i <= n; i++)
	{
		in[i] = (i - 1) / sz + 1;
		if(!lp[in[i]]) lp[in[i]] = i;
		rp[in[i]] = i;
	}
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> q[i].l >> q[i].r;
		q[i].id = i;
	}
	int ql = 1, qr = 0;
	sort(q + 1, q + m + 1, cmp);
	for(int i = 1; i <= m; i++)
	{
		if(in[q[i].l] != in[q[i - 1].l])
		{
			ql = rp[in[q[i].l]] + 1;
			qr = rp[in[q[i].l]];
			ret = 0;
			memset(cntr, 0, (tot + 1) * sizeof(int));
			memset(cntl, -1, (tot + 1) * sizeof(int));
		}
		if(in[q[i].l] == in[q[i].r]) ans[q[i].id] = bf(q[i].l, q[i].r);
		else
		{
			while(qr < q[i].r) add(++qr);
			int tmp = ret;
			for(int j = ql - 1; j >= q[i].l; j--)
				tmp = max(tmp, cntr[a[j]] - j);
			tmp = max(tmp, bf(q[i].l, ql - 1));
			ans[q[i].id] = tmp;
		}
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << '\n';
	return 0;
}