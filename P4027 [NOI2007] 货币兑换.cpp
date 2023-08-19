#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
const int N = 4e5 + 5;
int n, k, cnt;
int s[N], d[N];
double a[N], b[N], r[N], f[N], tmp[N];
struct line {double k, b;} t[N];
inline bool cmp(int u, int v, int x) {return t[u].k * tmp[x] + t[u].b > t[v].k * tmp[x] + t[v].b;}
inline void update(int p, int l, int r, int u)
{
	int mid = l + r >> 1, &v = s[p];
	if(cmp(u, v, mid)) swap(u, v);
	if(cmp(u, v, l)) update(ls, l, mid, u);
	if(cmp(u, v, r)) update(rs, mid + 1, r, u);
}
inline double query(int p, int l, int r, int x)
{
	double res = t[s[p]].k * tmp[x] + t[s[p]].b; int mid = l + r >> 1;
	if(l == r) return res;
	if(x <= mid) return max(res, query(ls, l, mid, x));
	else return max(res, query(rs, mid + 1, r, x));
}
int main()
{
	cin >> n >> k; f[0] = k;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> r[i], tmp[i] = a[i] / b[i];
	sort(tmp + 1, tmp + n + 1);
	int len = unique(tmp + 1, tmp + n + 1) - tmp - 1;
	for(int i = 1; i <= n; i++)
		d[i] = lower_bound(tmp + 1, tmp + n + 1, a[i] / b[i]) - tmp;
	for(int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1];
		f[i] = max(f[i], b[i] * query(1, 1, n, d[i]));
		t[++cnt] = {r[i] * f[i] / (r[i] * a[i] + b[i]), f[i] / (r[i] * a[i] + b[i])};
		update(1, 1, n, cnt);
	}
	printf("%.3lf", f[n]);
	return 0;
}
