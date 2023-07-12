#include<bits/stdc++.h>
using namespace std;
int T, n;
char s[100005], t1[100005], t2[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int cnt = 0, ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> s[i];
		for(int i = 1; i <= n; i++) cin >> t1[i];
		for(int i = 1; i <= n; i++) t2[i] = t1[n - i + 1];
		for(int i = 1; i <= n; i++)
			if(s[i] != t1[i])
				cnt++;
		if(cnt % 2) ans = cnt * 2 - 1;
		else ans = cnt * 2;
		cnt = 0;
		for(int i = 1; i <= n; i++)
			if(s[i] != t2[i])
				cnt++;
		if(cnt % 2) ans = min(ans, max(cnt * 2, 2));
		else ans = min(ans, max(cnt * 2 - 1, 2));
		cout << ans << '\n';
	}
	return 0;
}