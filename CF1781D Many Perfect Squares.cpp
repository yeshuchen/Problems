#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[505];
inline bool check(long long x)
{
	long long qx = sqrt(x);
	return qx * qx == x;
}
inline int solve()
{
	int ans = 1;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
		{
			int val = a[j] - a[i];
			for(int t = 1; t * t <= val; t++)
			{
				if(val % t != 0 || (val / t + t) % 2 == 1) continue;
				long long p = (val / t + t) / 2;
				int cnt = 0;
				long long x = p * p - a[j];
				if(x < 0) continue;
				for(int k = 1; k <= n; k++)
					if(check(a[k] + x)) cnt++;
				ans = max(ans, cnt);
			}
		}
	return ans;
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
		cout << solve() << '\n';
	}
	return 0;
}