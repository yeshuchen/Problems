#include<bits/stdc++.h>
using namespace std;
int T, n, m, q;
int t[500005], pos[500005];
int l[500005], r[500005];
inline bool check(int opt)
{
	memset(t, 0, sizeof(int) * (n + 1));
	for(int i = 1; i <= opt; i++)
		t[pos[i]] = 1;
	for(int i = 1; i <= n; i++) t[i] += t[i - 1];
	for(int i = 1; i <= m; i++)
		if(t[r[i]] - t[l[i] - 1] > (r[i] - l[i] + 1) / 2)
			return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		for(int i = 1; i <= m; i++)
			cin >> l[i] >> r[i];
		cin >> q;
		for(int i = 1; i <= q; i++)
			cin >> pos[i];
		int l = 1, r = q, ans;
		if(!check(q))
		{
			cout << -1 << '\n';
			continue;
		}
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(check(mid)) r = (ans = mid) - 1;
			else l = mid + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}