#include<bits/stdc++.h>
using namespace std;
int T;
char s[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int d[4] = {0, 0, 0, 0};
		int ans = INT_MAX;
		cin >> s + 1;
		int n = strlen(s + 1);
		int l = 1, r = 0;
		while(r <= n)
		{
			if(!d[1] || !d[2] || !d[3])
			{
				d[s[r + 1] - '0']++;
				r++; continue;
			}
			ans = min(ans, r - l + 1);
			d[s[l] - '0']--;
			l++;
		}
		if(ans == INT_MAX) ans = 0;
		cout << ans << '\n';
	}
	return 0;
}