#include<bits/stdc++.h>
using namespace std;
int c[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		int n, cnt = 0;
		map<char, bool> m;
		cin >> n;
		cin >> s;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			char p;
			cin >> p;
			m[p] = 1;
		}
		for(int i = 0; i < s.size(); i++)
			if(m[s[i]]) c[++cnt] = i;
		if(!cnt) {cout << 0 << '\n'; continue;}
		int ans = c[1];
		for(int i = 2; i <= cnt; i++)
			ans = max(ans, c[i] - c[i - 1]);
		cout << ans << '\n';
	}
	return 0;
}