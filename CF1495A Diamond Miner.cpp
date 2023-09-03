#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int T, n;
int t1[N], t2[N];
double ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		ans = 0;
		int res = 0, cnt = 0;
		cin >> n;
		for(int i = 1; i <= 2 * n; i++)
		{
			int x, y;
			cin >> x >> y;
			if(!x) t1[++res] = abs(y);
			else t2[++cnt] = abs(x);
		}
		sort(t1 + 1, t1 + res + 1);
		sort(t2 + 1, t2 + cnt + 1);
		for(int i = 1; i <= n; i++)
			ans = ans + sqrt(t1[i] * t1[i] + t2[i] * t2[i]);
		printf("%.15lf\n", ans);
	}
	return 0;
}