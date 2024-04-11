#include<bits/stdc++.h>
using namespace std;
const int N = 1.5 * 1e6 + 5;
int n, m, res;
int l1, l2;
int x[N], y[N], c[N];
struct query {
	int x1, y1, x2, y2;
} q[N];
int t1[N], t2[N], ans[N];
vector<int> g[N];
vector< pair<int, int> > v[N];
void add(int x) {for(int i = x; i <= l2; i += (i & -i)) c[i]++;}
int ask(int x) {int res = 0; for(int i = x; i; i -= (i & -i)) res += c[i]; return res;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		t1[++res] = x[i]; t2[res] = y[i];
	}
	for(int i = 1; i <= m; i++)
	{
		cin >> q[i].x1 >> q[i].y1 >> q[i].x2 >> q[i].y2;
		t1[++res] = q[i].x1; t2[res] = q[i].y1;
		t1[++res] = q[i].x2; t2[res] = q[i].y2;
	}
	sort(t1 + 1, t1 + res + 1);
	sort(t2 + 1, t2 + res + 1);
	l1 = unique(t1 + 1, t1 + res + 1) - t1 - 1;
	l2 = unique(t2 + 1, t2 + res + 1) - t2 - 1;
	for(int i = 1; i <= n; i++)
	{
		x[i] = lower_bound(t1 + 1, t1 + l1 + 1, x[i]) - t1;
		y[i] = lower_bound(t2 + 1, t2 + l2 + 1, y[i]) - t2;
		g[x[i]].push_back(y[i]);
	}
	for(int i = 1; i <= m; i++)
	{
		q[i].x1 = lower_bound(t1 + 1, t1 + l1 + 1, q[i].x1) - t1;
		q[i].x2 = lower_bound(t1 + 1, t1 + l1 + 1, q[i].x2) - t1;
		q[i].y1 = lower_bound(t2 + 1, t2 + l2 + 1, q[i].y1) - t2;
		q[i].y2 = lower_bound(t2 + 1, t2 + l2 + 1, q[i].y2) - t2;
		v[q[i].x1 - 1].push_back(make_pair(i, -1));
		v[q[i].x2].push_back(make_pair(i, 1));
	}
	for(int i = 1; i <= l1; i++)
	{
		for(int x : g[i]) add(x);
		for(auto x : v[i])
		{
			int id = x.first;
			ans[id] += x.second * (ask(q[id].y2) - ask(q[id].y1 - 1));
		}
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << '\n';
	return 0;
}