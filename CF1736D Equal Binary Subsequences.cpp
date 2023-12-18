#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int T, n;
char s[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		vector<int> v;
		int cnt = 0;
		cin >> n;
		for(int i = 1; i <= 2 * n; i++) cin >> s[i], cnt += s[i] - '1';
		if(cnt & 1) {cout << -1 << '\n'; continue;}
		cnt = 0; int r = 0;
		for(int i = 1; i <= 2 * n; i += 2)
		{
			if(s[i] != s[i + 1])
			{
				if(s[i] - '0' == r) v.push_back(i);
				else v.push_back(i + 1);
				r ^= 1;
			}
		}
		cout << v.size() << ' ';
		for(int x : v) cout << x << ' ';
		cout << '\n';
		for(int i = 1; i <= n; i++) cout << 2 * i - 1 << ' ';
		cout << '\n';
	}
	return 0;
}