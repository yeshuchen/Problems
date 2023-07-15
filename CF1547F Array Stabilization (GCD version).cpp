#include<bits/stdc++.h>
using namespace std;
int n;
int d[400005][20];
inline int query(int l, int r)
{
	int k = log2(r - l + 1);
	return __gcd(d[l][k], d[r - (1 << k) + 1][k]);
}
int t[200005];
inline bool check(int x)
{
	for(int i = 1; i <= n; i++)
		t[i] = query(i, i + x - 1);
	for(int i = 1; i < n; i++)
		if(t[i] != t[i + 1])
			return false;
	return true;
}
int T;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> d[i][0];
		for(int i = n + 1; i <= 2 * n; i++) d[i][0] = d[i - n][0];
		for(int j = 1; j <= 19; j++)
			for(int i = 1; i + (1 << j) - 1 <= 2 * n; i++)
				d[i][j] = __gcd(d[i][j - 1], d[i + (1 << j - 1)][j - 1]);
		int l = 1, r = n, ans;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(check(mid)) r = (ans = mid) - 1;
			else l = mid + 1;
		}
		cout << ans - 1 << '\n';
	}
	return 0;
}