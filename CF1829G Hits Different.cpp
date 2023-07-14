#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
int T, n;
ll f[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for(int i = 1; i <= 1000000; i++)
		f[i] = f[i - 1] + 1ll * i * i;
	while(T--)
	{
		int dep;
		cin >> n;
		for(int i = 1; i <= n; i++)
			if(i * (i + 1) / 2 >= n)
			{
				dep = i;
				break;
			}
		ll ans = 0;
		ll ldep = dep * (dep - 1) / 2 + 1;
		ll rdep = dep * (dep + 1) / 2;
		int l = n, r = n;
		int ld = n - ldep, rd = rdep - n;
		while(dep)
		{
			ans += f[r] - f[l - 1];
			dep--;
			ldep = dep * (dep - 1) / 2 + 1;
			rdep = dep * (dep + 1) / 2;
			ld = max(ld - 1, 0); rd = max(rd - 1, 0);
			l = ldep + ld; r = rdep - rd;
		}
		cout << ans << '\n';
	}
	return 0;
}