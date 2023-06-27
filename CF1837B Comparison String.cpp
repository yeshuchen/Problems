#include<bits/stdc++.h>
using namespace std;
int T, n;
char c[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int ans = 2, cnt = 1;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> c[i];
		for(int i = 2; i <= n; i++)
		{
			if(c[i] == c[i - 1]) cnt++;
			else cnt = 1;
			ans = max(ans, cnt + 1);
		}
		cout << ans << '\n';
	}
	return 0;
}