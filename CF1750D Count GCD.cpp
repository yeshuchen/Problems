#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int T, n, m;
int a[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int ans = 1;
		for(int i = 1; i < n; i++)
		{
			vector<int> v;
			if(a[i] % a[i + 1])
			{
				ans = 0;
				break;
			}
			int x = m / a[i + 1], y = a[i] / a[i + 1];
			for(int j = 2; j * j <= y; j++)
			{
				if(y % j != 0) continue;
				int p = v.size();
				for(int k = 0; k < p; k++) v.push_back(-v[k] * j);
				while(y % j == 0) y /= j;
				v.push_back(j);
			}
			if(y > 1)
			{
				int p = v.size();
				for(int j = 0; j < p; j++) v.push_back(-v[j] * y);
				v.push_back(y);
			}
			int cnt = 0;
			for(int j = 0; j < v.size(); j++)
				cnt = (cnt + x / v[j]) % mod;
			ans = 1ll * ans * (x - cnt) % mod;
		}
		cout << ans << '\n';
	}
	return 0;
}