#include<bits/stdc++.h>
using namespace std;
int T, n, k;
string s, t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		s = t = "";
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
		{
			char ch;
			cin >> ch;
			if(i & 1) s += ch;
			else t += ch;
		}
		if(k & 1)
		{
			sort(s.begin(), s.end());
			sort(t.begin(), t.end());
			for(int i = 0; i < n / 2; i++)
				cout << s[i] << t[i];
			if(n & 1) cout << s[n / 2];
			cout << '\n';
		}
		else
		{
			s += t;
			sort(s.begin(), s.end());
			cout << s << '\n';
		}
	}
	return 0;
}