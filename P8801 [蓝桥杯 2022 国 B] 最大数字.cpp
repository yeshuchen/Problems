#include<bits/stdc++.h>
using namespace std;
string s, ans, str;
int a, b, n;
inline void dfs(int pos, int use_a, int use_b) {
	if(pos == n)
	{
		if(ans < str) ans = str;
		return;
	}
	int c = '9' - s[pos], d = s[pos] - '0' + 1;
	if(use_a + c <= a && use_b + d <= b) {
		str[pos] = '9';
		dfs(pos + 1, use_a + c, use_b);
		dfs(pos + 1, use_a, use_b + d);
	}
	else if(use_a + c <= a) {
		str[pos] = '9';
		dfs(pos + 1, use_a + c, use_b);
	}
	else if(use_b + d <= b) {
		str[pos] = '9';
		dfs(pos + 1, use_a, use_b + d);
	}
	else {
		str[pos] = s[pos] + a - use_a;
		dfs(pos + 1, a, use_b);
	}
}
int main()
{
	cin >> s >> a >> b;
	n = s.size(); str = ans = s;
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}