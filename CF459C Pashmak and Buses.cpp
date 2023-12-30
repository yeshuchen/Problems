#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int ans[1005][1005];
void solve(int dep, int l, int r)
{
	if(dep > k || l > r) return;
	// cout << dep << ' ' << l << ' ' << r << '\n';
	int len = (r - l + m) / m;
	for(int i = l; i <= r; i++)
		ans[dep][i] = (i - l) / len + 1;
	if(len == 1) solve(dep + 1, l, r);
	else
	{
		for(int i = 1; i <= m; i++)
			solve(dep + 1, l + (i - 1) * len, min(l + i * len - 1, r));
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k; bool flag = 0;
	for(int i = 1, base = 1; i <= k; i++)
	{
		base *= m;
		if(base >= n)
		{
			flag = 1;
			break;
		}
	}
	if(!flag) {cout << -1; return 0;}
	solve(1, 1, n);
	for(int i = 1; i <= k; i++, cout << '\n')
		for(int j = 1; j <= n; j++)
			cout << ans[i][j] << ' ';
	return 0;
}