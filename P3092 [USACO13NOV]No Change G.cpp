#include<bits/stdc++.h>
using namespace std;
int n, m, ans = -1;
int a[20], c[100005], f[1000005];
long long s[1000006];
inline int ask(int w, int val){return upper_bound(s + 1, s + m + 1, s[w] + val) - s - 1;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> c[i], s[i] = s[i - 1] + c[i];
	for(int i = 1; i < (1 << n); i++)
		for(int j = 1; j <= n; j++)
			if(i & (1 << j - 1))
				f[i] = max(f[i], ask(f[i ^ (1 << j - 1)], a[j]));
	for(int i = 1; i < (1 << n); i++)
	{
		if(f[i] == m)
		{
			int res = 0;
			for(int j = 1; j <= n; j++)
			{
				res += a[j];
				if(i & (1 << j - 1))
					res -= a[j];
			}
			ans = max(ans, res);
		}
	}
	cout << ans;
	return 0;
}