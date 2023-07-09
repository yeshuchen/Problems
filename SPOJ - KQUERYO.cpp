#include<bits/stdc++.h>
using namespace std;
int n, size;
int a[400005], bl[400005];
vector< pair<int, int> > v[400005];
inline int find(int x, int k)
{
	int len = v[x].size() - 1;
	int l = 0, r = len, res;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(v[x][mid].first <= k) l = mid + 1;
		else r = (res = mid) - 1; 
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; size = sqrt(n);
	for(int i = 1; i <= n; i++)
		cin >> a[i], bl[i] = (i - 1) / size + 1;
	for(int i = 1; i <= n; i++)
		v[bl[i]].push_back(make_pair(a[i], i));
	int cnt = bl[n];
	for(int i = 1; i <= cnt; i++)
		sort(v[i].begin(), v[i].end());
	int lastans = 0, m;
	cin >> m;
	while(m--)
	{
		int l, r, k, ans = 0;
		cin >> l >> r >> k;
		l ^= lastans; r ^= lastans, k ^= lastans;
		if(r > n) r = n;
		if(l < 1) l = 1;
		if(l > r) {lastans = 0; cout << 0 << '\n'; continue;}
		for(int i = bl[l] + 1; i < bl[r]; i++)
		{
			int len = v[i].size();
			if(v[i][len - 1].first < k) continue;
			int pos = find(i, k);
			ans += len - pos;
		}
		if(bl[l] == bl[r])
		{
			for(int i = 0; i < v[bl[l]].size(); i++)
				if(v[bl[l]][i].first >= k && l <= v[bl[l]][i].second && v[bl[l]][i].second <= r)
					ans++;
		}
		else
		{
			for(int i = 0; i < v[bl[l]].size(); i++)
				if(v[bl[l]][i].first >= k && l <= v[bl[l]][i].second && v[bl[l]][i].second <= r)
					ans++;
			for(int i = 0; i < v[bl[r]].size(); i++)
				if(v[bl[r]][i].first >= k && l <= v[bl[r]][i].second && v[bl[r]][i].second <= r)
					ans++;
		}
		cout << ans << '\n';
		lastans = ans;
	}
	return 0;
}