#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, W;
struct node {
	int w, v;
	int num;
} a[N];
int dp[N];
bool cmp(node x, node y) {return x.num > y.num;}
bool check(int rate)
{
	for(int i = 1; i <= n; i++) a[i].num = a[i].v - rate * a[i].w;
	for(int i = 1; i <= W; i++) dp[i] = INT_MIN; dp[0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = W; j >= 0; j--)
			dp[min(j + a[i].w, W)] = max(dp[j] + a[i].num, dp[min(j + a[i].w, W)]);
	return dp[W] >= 0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> W;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].w >> a[i].v;
		a[i].v *= 1000;
	}
	int l = 1, r = 1e6, ans;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(check(mid)) l = (ans = mid) + 1;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}