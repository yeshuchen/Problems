#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
mt19937 my_rand(time(0));
int n, m;
int w[N], r[N], g[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; int res = 0, cnt = 0;
	for(int i = 1; i <= n; i++) w[i] = my_rand(), res += w[i];
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		r[y] += w[x];
		g[y] = r[y];
		cnt += w[x];
	}
	int q;
	cin >> q;
	for(int i = 1; i <= q; i++)
	{
		int op, x, y;
		cin >> op >> x;
		if(op == 1)
		{
			cin >> y;
			r[y] -= w[x];
			cnt -= w[x];
		}
		if(op == 2)
		{
			cnt -= r[x];
			r[x] = 0;
		}
		if(op == 3)
		{
			cin >> y;
			r[y] += w[x];
			cnt += w[x];
		}
		if(op == 4)
		{
			cnt += g[x] - r[x];
			r[x] = g[x];
		}
		cout << (cnt == res ? "YES\n" : "NO\n");
	}
	return 0;
}