#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k, ans;
int a[200005];
vector<int> v;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	v.push_back(1000000007);
	for(int i = 1; i <= m; i++)
		v.push_back(a[i]);
	sort(v.begin(), v.end());
	for(int i = 0; i < k; i++) ans += v[i];
	cout << ans << ' ';
	for(int i = m + 1; i <= n; i++)
	{
		int p = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		if(p < k) ans = ans + a[i] - v[k - 1];
		v.insert(v.begin() + p, a[i]);
		p = lower_bound(v.begin(), v.end(), a[i - m]) - v.begin();
		if(p < k) ans = ans - v[p] + v[k];
		v.erase(v.begin() + p);
		cout << ans << ' ';
	}
	return 0;
}