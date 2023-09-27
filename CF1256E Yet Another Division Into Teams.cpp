#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
int q[N], ans[N];
int dp[N], pos[N];
struct node {
	int id, v;
} t[N];
inline bool cmp(node x, node y) {return x.v < y.v;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> t[i].v, t[i].id = i;
	sort(t + 1, t + n + 1, cmp);
	int hd = 1, tl = 1;  dp[1] = dp[2] = INT_MIN;
	for(int i = 3; i <= n; i++)
	{
		pos[i] = q[hd]; dp[i] = dp[q[hd]] - t[q[hd] + 1].v + t[i].v;
		while(hd <= tl && dp[i - 2] - t[i - 1].v <= dp[q[hd]] - t[q[hd] + 1].v) tl--;
		q[++tl] = i - 2;
	}
	int x = n, cnt = 0;
	while(x)
	{
		cnt++;
		for(int i = pos[x] + 1; i <= x; i++)
			ans[t[i].id] = cnt;
		x = pos[x];
	}
	cout << dp[n] << ' ' << cnt << '\n';
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}