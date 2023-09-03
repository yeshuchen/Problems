#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int T;
char s[N], t[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		bool f = 0;
		cin >> s + 1;
		cin >> t + 1;
		int len = strlen(s + 1);
		for(int i = 1; i < len; i++)
			if(s[i] == '0' && t[i] == '0' && s[i + 1] == '1' && t[i + 1] == '1')
				f = 1;
		if(f) cout << "YES\n";
		else cout << "NO\n";
	}
}