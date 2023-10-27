#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, maxn = 2e6;
int n, ans, vis[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1, x; i <= n; i++) cin >> x, vis[x] = x;
	for(int i = 1; i <= maxn; i++) vis[i] = max(vis[i], vis[i - 1]);
	for(int rat = 1; rat <= maxn; rat++)
		for(int i = 1; i * rat + i - 1 <= maxn; i++)
		{
			if(vis[i] != i) continue;
			ans = max(ans, vis[i * rat + i - 1] - i * rat);
		}
	cout << ans;
	return 0;
}