#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, t, st, ed, tot;
int tmp[100005], x[1005], y[1005], z[1005];
struct mat {
	int c[205][205];
	mat ()
	{
		for(int i = 1; i <= tot; i++)
			for(int j = 1; j <= tot; j++)
				c[i][j] = inf;
	}
	mat operator * (const mat &t)
	{
		mat base;
		for(int i = 1; i <= tot; i++)
			for(int j = 1; j <= tot; j++)
				for(int k = 1; k <= tot; k++)
					base.c[i][j] = min(base.c[i][j], c[i][k] + t.c[k][j]);
		return base;
	}
};
mat qpow(mat a, int b)
{
	mat base;
	for(int i = 1; i <= tot; i++) base.c[i][i] = 0;
	while(b)
	{
		if(b & 1) base = base * a;
		a = a * a;
		b >>= 1;
	}
	return base;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> t >> st >> ed;
	tmp[++tot] = st; tmp[++tot] = ed;
	for(int i = 1; i <= t; i++)
	{
		cin >> z[i] >> x[i] >> y[i];
		tmp[++tot] = x[i];
		tmp[++tot] = y[i];
	}
	mat ans;
	sort(tmp + 1, tmp + tot + 1);
	tot = unique(tmp + 1, tmp + tot + 1) - tmp - 1;
	st = lower_bound(tmp + 1, tmp + tot + 1, st) - tmp;
	ed = lower_bound(tmp + 1, tmp + tot + 1, ed) - tmp;
	// cout << st << ' ' << ed << '\n';
	for(int i = 1; i <= t; i++)
	{
		x[i] = lower_bound(tmp + 1, tmp + tot + 1, x[i]) - tmp;
		y[i] = lower_bound(tmp + 1, tmp + tot + 1, y[i]) - tmp;
		ans.c[x[i]][y[i]] = ans.c[y[i]][x[i]] = z[i];
	}
	ans = qpow(ans, n);
	cout << ans.c[st][ed];
	return 0;
}