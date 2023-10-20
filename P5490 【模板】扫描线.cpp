#include<bits/stdc++.h>
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
const int N = 4e5 + 5;
int n, tot;
int tmp[N];
struct Line {
	int l, r, h, f;
} line[N];
struct node {
	int v, sum;
} t[N << 2];
bool cmp(Line x, Line y) {return x.h < y.h;}
void pushup(int p, int l, int r)
{
	if(t[p].v) t[p].sum = tmp[r + 1] - tmp[l];
	else t[p].sum = t[ls].sum + t[rs].sum;
}
void update(int p, int l, int r, int L, int R, int x)
{
	if(L <= tmp[l] && tmp[r + 1] <= R)
	{
		t[p].v += x;
		pushup(p, l, r);
		return;
	}
	int mid = l + r >> 1;
	if(L <= tmp[mid]) update(ls, l, mid, L, R, x);
	if(R > tmp[mid + 1]) update(rs, mid + 1, r, L, R, x);
	pushup(p, l, r);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x, y, xx, yy;
		cin >> x >> y >> xx >> yy;
		tmp[++tot] = x; tmp[++tot] = xx;
		line[i] = {x, xx, y, 1};
		line[i + n] = {x, xx, yy, -1};
	}
	n <<= 1; int ans = 0;
	sort(tmp + 1, tmp + tot + 1);
	sort(line + 1, line + n + 1, cmp);
	tot = unique(tmp + 1, tmp + tot + 1) - tmp - 1;
	update(1, 1, tot - 1, line[1].l, line[1].r, line[1].f);
	for(int i = 2; i <= n; i++)
	{
		ans += (line[i].h - line[i - 1].h) * t[1].sum;
		update(1, 1, tot - 1, line[i].l, line[i].r, line[i].f);
	}
	cout << ans;
	return 0;
}