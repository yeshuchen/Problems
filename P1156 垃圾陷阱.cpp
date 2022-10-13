#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int H, n;
int dp[4005];
struct node{
	int t, f, h;
}a[N];
inline bool cmp(node x, node y)
{
	return x.t < y.t;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> H >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].t >> a[i].f >> a[i].h;
	sort(a + 1, a + n + 1, cmp);
	dp[0] = dp[0] = 10;
	for(int i = 1; i <= 1000; i++) dp[i] = INT_MIN;
	for(int i = 1; i <= n; i++)
		for(int j = H; j >= 0; j--)
		{
			//第i个垃圾掉进来
			if(dp[j] >= a[i].t)
			{
				dp[min(j + a[i].h, H)] = max(dp[j], dp[min(j + a[i].h, H)]);
				dp[j] += a[i].f;
			}
			if(dp[H] >= 0)
			{
				cout << a[i].t << '\n';
				return 0;
			}
		}
	cout << dp[0];
	return 0;
}
/*
考虑这样一件事情。
考虑设计这样一个状态
dp[i] 表示在高度是 i 的情况下，能活多久
*/