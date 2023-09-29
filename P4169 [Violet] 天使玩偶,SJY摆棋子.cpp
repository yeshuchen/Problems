#include<bits/stdc++.h>
using namespace std;
int n, m;
const int N = 6e5 + 5, mx = 2e6;
struct node {
	int x, y, id;
	node () {id = 0;}
} t[N], tmp[N], temp[N];
int c[mx + 5], ans[N];
inline bool cmpx(node x, node y) {return x.x < y.x;}
inline void add(int x, int y) {
	for(int i = x; i <= mx; i += (i & -i))
	{
		if(!c[i] && y == -1) return;
		c[i] = (y == -1 ? 0 : max(c[i], y));
	}
}
inline int ask(int x) {int res = 0; for(int i = x; i; i -= (i & -i)) res = max(res, c[i]); return res;}
inline void solve(int l, int r)
{
	int mid = l + r >> 1, res = 0;
	if(l == r) return;
	solve(l, mid);
	solve(mid + 1, r);
	int i = l;
	for(int j = mid + 1; j <= r; j++)
	{
		while(i <= mid && t[i].x <= t[j].x)
		{
			temp[++res] = t[i];
			if(!t[i].id)
				add(t[i].y, t[i].x + t[i].y);
			i++; 
		}
		temp[++res] = t[j];
		if(t[j].id)
		{
			int k = ask(t[j].y);
			if(k) ans[t[j].id] = min(t[j].x + t[j].y - k, ans[t[j].id]);
		}
	}
	for(int k = l; k <= i; k++) 
		add(t[k].y, -1);
	while(i <= mid) temp[++res] = t[i++];
	for(int k = 1; k <= res; k++) t[l++] = temp[k];
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> t[i].x >> t[i].y, t[i].x++, t[i].y++, tmp[i] = t[i];
	int ret = 0;
	for(int i = 1; i <= m; i++)
	{
		int op, x, y; n++;
		cin >> op >> x >> y;
		x++; y++;
		t[n].x = x; t[n].y = y;
		if(op == 2) t[n].id = ++ret;
		tmp[n] = t[n];
	}
	for(int i = 1; i <= ret; i++) ans[i] = INT_MAX;
	for(int k = 1; k <= 4; k++)
	{
		// for(int i = 1; i <= n; i++)
		// 	cout << t[i].x << ' ' << t[i].y << '\n';
		for(int i = 1; i <= n; i++) t[i] = tmp[i];
		solve(1, n);	
		for(int i = 1; i <= n; i++)
		{
			int x = tmp[i].x, y = tmp[i].y;
			tmp[i].x = y; tmp[i].y = mx - x + 1;
		}
	}
	for(int i = 1; i <= ret; i++)
		cout << ans[i] << '\n';
	return 0;
}