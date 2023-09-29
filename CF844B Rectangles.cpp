#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e4 + 4;
int n, m;
int p[N];
int row[N], col[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	p[0] = 1;
	for(int i = 1; i <= max(n, m); i++) p[i] = p[i - 1] * 2;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			int x;
			cin >> x;
			row[i] += x;
			col[j] += x;
		}
	int ans = n * m;
	for(int i = 1; i <= n; i++)
		ans += p[row[i]] - row[i] - 1 + p[m - row[i]] - m + row[i] - 1;
	for(int i = 1; i <= m; i++)
		ans += p[col[i]] - col[i] - 1 + p[n - col[i]] - n + col[i] - 1;
	cout << ans;
	return 0;
}