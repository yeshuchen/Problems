#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, d, k;
int x[N], s[N];
inline bool check(int x)
{
	for(int i = 1; i <= n; i++)
	{
		
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> d >> k;
	int res = 0;
	for(int i = 1; i <= n; i++)
		cin >> x[i] >> s[i], res += max(s[i], 0);
	if(res < k) {cout << -1 << '\n'; return 0;}
	int l = 0, r = x[n], ans;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = (ans = mid) - 1;
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}