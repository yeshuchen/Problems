#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, ans;
int a[N];
map<int, int> m;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], m[a[i]]++;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		int res = a[i], cnt = 0;
		while(m[res])
		{
			cnt += m[res] * res; m[res] = 0;
			if(res & 1) break;
			else res = res / 2 * 3;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}	