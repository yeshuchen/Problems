#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, a, b, T;
int ans, s[N];
int check(int pos, int num, int p)
{
	int x = s[p] + s[n] - s[pos - 1] + min(2 * (n - pos + 1) + (p - 1), 2 * (p - 1) + (n - pos + 1)) * a;
	return x <= num;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> a >> b >> T;
	for(int i = 1; i <= n; i++)
	{
		char ch;
		cin >> ch;
		s[i] = s[i - 1] + (ch == 'w') * b + 1;
	}
	for(int i = 1; i <= n; i++)
	{
		if(s[i] + (i - 1) * a > T) break;
		int l = i + 1, r = n, pos = n + 1;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(check(mid, T, i)) r = (pos = mid) - 1;
			else l = mid + 1;
		}
		ans = max(i + n - pos + 1, ans);
	}
	cout << ans;
	return 0;
}