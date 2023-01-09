#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int T, n, a[N];
vector<int> w1[N], w2[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int tot = 0, ans = INT_MAX;
		cin >> n;
		w1[0].clear(); w2[0].clear();
		for(int i = 1; i <= n; i++)
			cin >> a[i], w1[i].clear(), w2[i].clear(), tot += a[i];
		int p = n / 2;
		for(int i = 0; i < (1 << p); i++)
		{
			int cnt = 0, sum = 0;
			for(int j = 0; j < p; j++)
				if(i & (1 << j))
					sum += a[j + 1], cnt++;
			w1[cnt].push_back(sum);
		}
		for(int i = 0; i < (1 << n - p); i++)
		{
			int cnt = 0, sum = 0;
			for(int j = 0; j < n - p; j++)
				if(i & (1 << j))
					sum += a[j + p + 1], cnt++;
			w2[cnt].push_back(sum);
		}
		for(int i = 0; i <= p; i++)
			sort(w1[i].begin(), w1[i].end());
		for(int i = 0; i < n - p; i++)
			sort(w2[i].begin(), w2[i].end());
		for(int i = 0; i <= p; i++)
		{
			int need = p - i;
			for(int j = 0; j < w1[i].size(); j++)
			{
				int v = w1[i][j];
				for(int k = 0; k < w2[need].size(); k++)
					ans = min(ans, abs(v + w2[need][k] - (tot - v - w2[need][k])));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}