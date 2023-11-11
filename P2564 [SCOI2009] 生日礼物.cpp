#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, tot, tmp[N];
vector<int> v[N], c[N];
int cnt[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			int x;
			cin >> x;
			v[i].push_back(x);
			tmp[++tot] = x;
		}
	}
	sort(tmp + 1, tmp + tot + 1);
	tot = unique(tmp + 1, tmp + tot + 1) - tmp - 1;
	for(int i = 1; i <= m; i++)
		for(int j = 0; j < v[i].size(); j++)
		{
			v[i][j] = lower_bound(tmp + 1, tmp + tot + 1, v[i][j]) - tmp;
			c[v[i][j]].push_back(i);
		}
	int res = 0, r = 0, ans = INT_MAX;
	for(int i = 1; i <= tot; i++)
	{
		while(r <= tot && res < m)
		{
			r++;
			for(int x : c[r])
			{
				if(!cnt[x]) res++;
				cnt[x]++;
			}
		}
		// cout << i << ' ' << r << '\n';
		if(res == m) ans = min(ans, tmp[r] - tmp[i]);
		for(int x : c[i])
		{
			cnt[x]--;
			if(!cnt[x]) res--;
		}
	}
	cout << ans;
	return 0;
}