#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, ans;
char s[N], t[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> s + 1;
	cin >> t + 1;
	for(int i = 1; i <= n / 2; i++)
	{
		char c[4] = {s[i], t[i], s[n - i + 1], t[n - i + 1]};
		if(c[0] == c[1] && c[2] == c[3] || c[0] == c[3] && c[1] == c[2] || c[0] == c[2] && c[1] == c[3]) continue;
		else if(c[0] != c[1] && c[0] != c[3] && c[2] != c[1] && c[2] != c[3] && c[1] != c[3]) ans += 2;
		else ans++;
	}
	if(n & 1)
		if(s[n / 2 + 1] != t[n / 2 + 1])
			ans++;
	cout << ans;
	return 0;
}