#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, maxv = 2e5;
struct node {
	int a, b, c, cnt, res;
} t[N], a[N];
int n, k, ans[N];
bool cmpa(node x, node y) {return (x.a == y.a ? (x.b == y.b ? x.c < y.c : x.b < y.b) : x.a < y.a);}
bool cmpb(node x, node y) {return (x.b == y.b ? x.c < y.c : x.b < y.b);}
int c[N];
inline void add(int x, int v)
{
	for(int i = x; i <= maxv; i += (i & -i))
		c[i] += v;
}
inline int ask(int x)
{
	int res = 0;
	for(int i = x; i; i -= (i & -i))
		res += c[i];
	return res;
}
inline void CDQ(int l, int r)
{
	int mid = l + r >> 1;
	if(l == r) return;
	CDQ(l, mid);
	CDQ(mid + 1, r);
	sort(t + l, t + mid + 1, cmpb);
	sort(t + mid + 1, t + r + 1, cmpb);
	int i = l, j = mid + 1;
	while(j <= r)
	{
		while(i <= mid && t[i].b <= t[j].b)
		{
			add(t[i].c, t[i].cnt);
			i++;
		}
		t[j].res += ask(t[j].c); j++;
	}
	for(int k = l; k < i; k++) add(t[k].c, -t[k].cnt);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i].a >> a[i].b >> a[i].c;
	sort(a + 1, a + n + 1, cmpa);
	int ret = 0, m = 0;
	for(int i = 1; i <= n; i++)
	{
		ret++;
		if(a[i].a != a[i + 1].a || a[i].b != a[i + 1].b || a[i].c != a[i + 1].c)
		{
			t[++m].a = a[i].a;
			t[m].b = a[i].b;
			t[m].c = a[i].c;
			t[m].cnt = ret;
			ret = 0;
		}
	}
	CDQ(1, m);
	for(int i = 1; i <= m; i++) ans[t[i].res + t[i].cnt - 1] += t[i].cnt;
	for(int i = 0; i < n; i++) cout << ans[i] << '\n';
	return 0;
}