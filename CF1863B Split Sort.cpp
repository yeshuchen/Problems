#include<bits/stdc++.h>
using namespace std;
int T, n, a[200005], d[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n; int ans = 0;
		for(int i = 1; i <= n; i++)
			cin >> a[i], d[i] = 0;
		set<int> s;
		for(int i = 1; i <= n; i++)
		{
			auto it = s.lower_bound(a[i]);
			s.insert(a[i]);
			if(it == s.end()) continue;
			if(!d[*it]) d[*it] = 1, ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}