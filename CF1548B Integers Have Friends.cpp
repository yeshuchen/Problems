#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int T, n;
ll a[N];
ll d[N][20];
inline ll check(int l, int r)
{
	int k = log2(r - l + 1);
	return __gcd(d[l][k], d[r - (1 << k) + 1][k]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int ans = 1; n--;
		for(int i = 1; i <= n; i++)
			d[i][0] = abs(a[i + 1] - a[i]);
		for(int j = 1; j <= 19; j++)
			for(int i = 1; i + (1 << j) - 1 <= n; i++)
				d[i][j] = __gcd(d[i][j - 1], d[i + (1 << j - 1)][j - 1]);
		for(int i = 1; i <= n; i++)
		{
			int l = i, r = n, p = i - 2;
			while(l <= r)
			{
				int mid = l + r >> 1;
				if(check(i, mid) > 1) l = (p = mid) + 1;
				else r = mid - 1;
			}
			ans = max(ans, p - i + 2);
		}
		cout << ans << '\n';
	}
	return 0;
}