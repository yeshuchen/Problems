#include<bits/stdc++.h>
using namespace std;
int T, n;
char c[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int ans = 8;
		cin >> n;
		string s;
		cin >> s;
		if(s.find("aa") < s.size()) cout << 2 << '\n';
		else if(s.find("aca") < s.size() || s.find("aba") < s.size()) cout << 3 << '\n';
		else if(s.find("abca") < s.size() || s.find("acba")< s.size()) cout << 4 << '\n';
		else if(s.find("abbacca") < s.size() || s.find("accabba") < s.size()) cout << 7 << '\n';
		else cout << -1 << '\n';
	}
	return 0;
}