#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n;
int a[5005];
int f[105][10005];
int num[10005], C[105][105];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
		cin >> a[i], num[a[i]]++;
	C[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= i; j++)
		{
			if(j == 0) C[i][j] = 1;
			else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	sort(a + 1, a + n + 1);
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(a[i] != a[i - 1]) cnt++;
	if(cnt <= 2) {cout << n; return 0;}
	for(int i = 1; i <= n; i++)
		for(int j = i; j; j--)
			for(int k = 10000; k >= a[i]; k--)
				f[j][k] = (f[j][k] + f[j - 1][k - a[i]]) % mod;
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j * i <= 10000; j++)
			if(f[i][j * i] == C[num[j]][i] && num[j] >= i)
				ans = i;
	cout << ans;
	return 0;
}