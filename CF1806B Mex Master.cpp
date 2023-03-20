#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[300005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int cnt = 0, maxn = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i], cnt += (a[i] == 0), maxn = max(maxn, a[i]);
		if(cnt <= (n + 1) / 2) cout << 0 << '\n';
		else if(maxn == 1) cout << 2 << '\n';
		else cout << 1 << '\n';
	}
	return 0;
}