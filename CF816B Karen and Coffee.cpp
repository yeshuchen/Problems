#include<bits/stdc++.h>
using namespace std;
int n, k, q;
int p[1000005], ans[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k >> q;
	for(int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		p[l]++; p[r + 1]--;
	}
	for(int i = 1; i <= 200000; i++)
		p[i] += p[i - 1];
	for(int i = 1; i <= 200000; i++)
		if(p[i] >= k)
			ans[i] = 1;
	for(int i = 1; i <= 200000; i++)
		ans[i] += ans[i - 1];
	for(int i = 1; i <= q; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << ans[r] - ans[l - 1] << '\n';
	}
	return 0;
}