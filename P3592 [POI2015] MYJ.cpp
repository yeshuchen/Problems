#include<bits/stdc++.h>
using namespace std;
const int N = 4e3 + 5;
int n, m;
int cnt[N];
int f[55][55][N];
int a[N], b[N], c[N], t[N];
struct node {
	int p, k;
} pos[55][55][N];
int p[N];
inline void print(int l, int r, int w)
{
	if(l > r) return;
	p[pos[l][r][w].p] = pos[l][r][w].k;
	print(l, pos[l][r][w].p - 1, pos[l][r][w].k);
	print(pos[l][r][w].p + 1, r, pos[l][r][w].k);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		cin >> a[i] >> b[i] >> c[i], t[i] = c[i];
	sort(t + 1, t + m + 1);
	int len = unique(t + 1, t + m + 1) - t - 1;
	for(int i = 1; i <= m; i++)
		c[i] = lower_bound(t + 1, t + len + 1, c[i]) - t;
	cout << '\n';
	for(int LEN = 1; LEN <= n; LEN++)
		for(int l = 1; l + LEN - 1 <= n; l++)
		{
			int r = l + LEN - 1;
			for(int w = len; w; w--) pos[l][r][w] = {l, w};
			for(int k = l; k <= r; k++)
			{
				for(int p = 1; p <= m; p++)
					if(l <= a[p] && a[p] <= k && k <= b[p] && b[p] <= r)
						cnt[c[p]]++;
				for(int w = len; w; w--)
				{
					cnt[w] += cnt[w + 1];
					if(f[l][k - 1][w] + f[k + 1][r][w] + t[w] * cnt[w] > f[l][r][w]) 
					{
						f[l][r][w] = f[l][k - 1][w] + f[k + 1][r][w] + t[w] * cnt[w];
						pos[l][r][w] = {k, w};
					}
				}
				for(int w = len; w; w--)
					cnt[w] = 0;
			}
			for(int w = len; w; w--)
				if(f[l][r][w + 1] > f[l][r][w])
				{
					f[l][r][w] = f[l][r][w + 1];
					pos[l][r][w] = pos[l][r][w + 1];
				}
				
		}
	cout << f[1][n][1] << '\n';
	print(1, n, 1);
	for(int i = 1; i <= n; i++) cout << t[p[i]] << ' ';
	return 0;
}