#include<bits/stdc++.h>
using namespace std;
int T;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> s;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '?') s[i] = '0';
			else break;
		}
		for(int i = s.size() - 1; i >= 0; i--)
		{
			if(s[i] == '?') s[i] = '1';
			else break;
		}
		int l = -1, r = -1;
		for(int i = 1; i < s.size() - 1; i++)
		{
			if(s[i] == '?' && s[i - 1] != '?') l = i - 1;
			if(s[i] == '?' && s[i + 1] != '?') r = i + 1;
			if(l != -1 && r != -1)
			{
				if(s[l] == s[r] && s[l] == '1') for(int j = l + 1; j < r; j++) s[j] = '1';
				else for(int j = l + 1; j < r; j++) s[j] = '0';
				l = r = -1;
			}
		}
		cout << s << '\n';
	}
	return 0;
}