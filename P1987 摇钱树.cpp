#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
struct node {
	int v, d;
} t[N];
int n, k;
int mx[1005];
int dp[1005][1005];
inline bool cmp(node x, node y) {return x.d == y.d ? x.v < y.v : x.d > y.d;};
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(cin >> n >> k)
	{
		if(!n && !k) break;
		memset(mx, 0, sizeof(mx));
		memset(dp, -1, sizeof(dp));
		int ans = 0;
		for(int i = 1; i <= n; i++)	cin >> t[i].v;
		for(int i = 1; i <= n; i++) cin >> t[i].d;
		sort(t + 1, t + n + 1, cmp);
		dp[0][0] = 0;
		for(int i = 1; i <= n; i++)
			for(int l = min(k, i); l; l--)
			{
				dp[i][l] = mx[l - 1] + max(t[i].v - (l - 1) * t[i].d, 0ll);
				mx[l] = max(mx[l], dp[i][l]);
			}
		// for(int i = 1; i <= n; i++, cout << '\n')
		// 	for(int j = 1; j <= k; j++)
		// 		cout << dp[i][j] << ' ';
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= k; j++)
				ans = max(ans, dp[i][j]);
		cout << ans << '\n';
	}
	return 0;
}