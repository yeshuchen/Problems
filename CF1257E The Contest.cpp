#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n1, n2, n3;
int minn[N];
int cnt1[N], cnt2[N], cnt3[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n1 >> n2 >> n3;
	for(int i = 1, x; i <= n1; i++)
		cin >> x, cnt1[x]++;
	for(int i = 1, x; i <= n2; i++)
		cin >> x, cnt2[x]++;
	for(int i = 1, x; i <= n3; i++)
		cin >> x, cnt3[x]++;
	int n = n1 + n2 + n3;
	for(int i = 1; i <= n; i++)
	{
		cnt1[i] += cnt1[i - 1];
		cnt2[i] += cnt2[i - 1];
		cnt3[i] += cnt3[i - 1];
	}
	minn[n + 1] = INT_MAX;
	for(int i = n; i >= 0; i--)
		minn[i] = min(cnt3[i] - cnt2[i], minn[i + 1]);
	int ans = INT_MAX;
	for(int i = 0; i <= n; i++)
		ans = min(ans, cnt2[i] - cnt1[i] + minn[i] + cnt1[n] + cnt2[n]);
	cout << ans;
	return 0;
}