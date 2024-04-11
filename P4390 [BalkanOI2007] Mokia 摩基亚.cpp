#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int op, n, res;
int ans[N];
struct que {
	int op, x, y, val;
} q[N];
int len, c[N], tmp[N];
bool cmp(que x, que y) {return x.x < y.x;}
void add(int x, int v) {for(int i = x; i <= len; i += (i & -i)) c[i] += v;}
int ask(int x) {int res = 0; for(int i = x; i; i -= (i & -i)) res += c[i]; return res;}
void solve(int l, int r)
{
	if(l == r) return; 
	int mid = l + r >> 1, res = 0;
	solve(l, mid);
	solve(mid + 1, r);
	sort(q + l, q + mid + 1, cmp);
	sort(q + mid + 1, q + r + 1, cmp);
	for(int i = l; i <= mid; i++)
		if(q[i].op == 0) tmp[++res] = q[i].y;
	for(int i = mid + 1; i <= r; i++)
		if(q[i].op != 0) tmp[++res] = q[i].y;
	sort(tmp + 1, tmp + res + 1);
	len = unique(tmp + 1, tmp + res + 1) - tmp - 1;
	for(int i = 1; i <= len; i++) c[i] = 0;
	int vis = l;
	for(int pos = mid + 1; pos <= r; pos++)
	{
		if(q[pos].op == 0) continue;
		while(q[vis].x <= q[pos].x && vis <= mid)
		{
			if(q[vis].op == 0) add(lower_bound(tmp + 1, tmp + len + 1, q[vis].y) - tmp, q[vis].val);
			vis++;
		}
		ans[q[pos].val] += q[pos].op * ask(lower_bound(tmp + 1, tmp + len + 1, q[pos].y) - tmp);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(cin >> op)
	{
		int x1, y1, x2, y2, a;
		if(op == 0) {cin >> x1; continue;}
		if(op == 3) break;
		cin >> x1 >> y1 >> x2;
		if(op == 2) 
		{
			n++;
			cin >> y2;
			q[++res] = {1, x1 - 1, y1 - 1, n};
			q[++res] = {1, x2, y2, n};
			q[++res] = {-1, x1 - 1, y2, n};
			q[++res] = {-1, x2, y1 - 1, n};
		}
		else q[++res] = {0, x1, y1, x2};
	}
	solve(1, res);
	for(int i = 1; i <= n; i++) cout << ans[i] << '\n';
	return 0;
}