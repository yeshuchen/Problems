#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, T, k;
ll c[1000005];
struct matrix {
	int r, c;
	ll a[255][255];
	inline void init()
	{
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= c; j++)
				a[i][j] = INT_MIN;
	}
} p[105], ans;
struct festival {
	int t, x, y;
} ftv[10005];
inline int id(int x, int y) {return (x - 1) * 5 + y;}
matrix operator * (const matrix &a, const matrix &b) {
	matrix c;
	c.r = a.r; c.c = b.c;
	c.init();
	for(int i = 1; i <= a.r; i++)
		for(int k = 1; k <= a.c; k++)
		{
			if(a.a[i][k] < 0) continue;
			for(int j = 1; j <= a.c; j++)
				c.a[i][j] = max(c.a[i][j], a.a[i][k] + b.a[k][j]);
		}
	return c;
}
inline bool cmp(festival a, festival b) {return a.t < b.t;}
inline void solve(int x)
{
	for(int i = 0; i < 30; i++)
		if(x & (1 << i))
			ans = ans * p[i];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> T >> k;
	p[0].r = p[0].c = 5 * n; ans.r = ans.c = 5 * n;
	p[0].init(); ans.init();
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
		for(int j = 1; j < 5; j++)
			p[0].a[id(i, j)][id(i, j + 1)] = 0;
	}
	for(int i = 1; i <= m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		p[0].a[id(x, w)][id(y, 1)] = c[y];
	}
	for(int i = 1; i < 30; i++) p[i] = p[i - 1] * p[i - 1];
	for(int i = 1; i <= k; i++) cin >> ftv[i].t >> ftv[i].x >> ftv[i].y;
	sort(ftv + 1, ftv + k + 1, cmp);
	ans.a[1][1] = c[1];
	for(int i = 1; i <= k; i++)
	{
		solve(ftv[i].t - ftv[i - 1].t - 1);
		for(int j = 1; j <= 5 * n; j++) p[0].a[j][id(ftv[i].x, 1)] += ftv[i].y;
		ans = ans * p[0];
		for(int j = 1; j <= 5 * n; j++) p[0].a[j][id(ftv[i].x, 1)] -= ftv[i].y;
	}
	solve(T - ftv[k].t);
	cout << (ans.a[1][1] < 0 ? -1 : ans.a[1][1]);
	return 0;
} 