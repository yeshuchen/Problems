#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		cout << s;
		reverse(s.begin(), s.end());
		cout << s << '\n';
	}
	return 0;
}