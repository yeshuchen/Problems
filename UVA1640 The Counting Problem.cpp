#include<bits/stdc++.h>
#define int long long
using namespace std;
int l, r;
int b[15], dp[15], cnt1[15], cnt2[15];
inline void solve(int p, int *cnt)
{
	int a[15], n = 0, tmp = p;
	while(p)
	{
		a[++n] = p % 10;
		p /= 10;
	}
	for(int i = n; i; i--)
	{
		int num = 0;
		for(int j = 0; j < 10; j++) cnt[j] += a[i] * dp[i - 1];
		for(int j = 0; j < a[i]; j++) cnt[j] += b[i - 1];
		tmp = tmp - b[i - 1] * a[i];
		cnt[a[i]] += tmp + 1;
		cnt[0] -= b[i - 1];
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	b[0] = 1;
	for(int i = 1; i <= 13; i++) b[i] = b[i - 1] * 10;
	for(int i = 1; i <= 13; i++)
		dp[i] = 10 * dp[i - 1] + b[i - 1];
	while(cin >> l >> r)
	{
		if(!l && !r) break;	
		if(l > r) swap(l, r);
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		solve(l - 1, cnt1);
		solve(r, cnt2);
		for(int i = 0; i < 10; i++)
			cout << cnt2[i] - cnt1[i] << " \n"[i == 9];
	}
	return 0;
}