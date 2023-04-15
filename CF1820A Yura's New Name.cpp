#include<bits/stdc++.h>
using namespace std;
int T;
char s[105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int ans = 0;
		cin >> s + 1;
		int n = strlen(s + 1);
		if(n == 1 && s[1] == '^') {cout << 1 << '\n'; continue;}
		if(s[1] == '_') ans++;
		for(int i = 1; i <= n; i++)
			if(s[i] == '_' && s[i + 1] != '^') ans++;
		cout << ans << '\n';
	}
	return 0;
}