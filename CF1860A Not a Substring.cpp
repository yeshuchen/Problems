#include<bits/stdc++.h>
using namespace std;
int T;
int main()
{
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		if(s == "()") {cout << "NO\n"; continue;}
		cout << "YES\n";
		bool f = 0;
		for(int i = 1; i < s.size(); i++)
			if(s[i] == s[i - 1]) f = 1;
		if(f)
			for(int i = 1; i <= s.size(); i++) cout << "()";
		else
		{
			for(int i = 1; i <= s.size(); i++) cout << '(';
			for(int i = 1; i <= s.size(); i++) cout << ')';
		}
		cout << '\n';
	}
	return 0;
}