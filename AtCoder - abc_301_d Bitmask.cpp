#include<bits/stdc++.h>
using namespace std;
string s;
long long n, res;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s >> n;
	for(int i = 0; i < s.size(); i++)
		if(s[i] == '1') res += (1ll << (s.size() - i - 1));
	if(res > n) {cout << -1; return 0;}
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '?' && res + (1ll << (s.size() - i - 1)) <= n)
			res += (1ll << (s.size() - i - 1));
	}
	cout << res;
	return 0;
}