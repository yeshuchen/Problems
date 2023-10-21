#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(getline(cin, s))
	{
		int ans = 0;
		if(s == "#") break;
		for(int i = 0; i < s.size(); i++)
			if(s[i] >= 'A' && s[i] <= 'Z')
				ans += (i + 1) * (s[i] - 'A' + 1);
		cout << ans << '\n';
	}
	return 0;
}