#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n, m, cnt = 0;
		string s1, s2;
		cin >> n >> m;
		cin >> s1 >> s2;
		for(int i = 0; i < n - 1; i++)
			if(s1[i] == s1[i + 1]) cnt++;
		for(int i = 0; i < m - 1; i++)
			if(s2[i] == s2[i + 1]) cnt++;
		if(s1[n - 1] == s2[m - 1] && cnt || s1[n - 1] != s2[m - 1] && cnt > 1) cout << "NO\n";
		else cout << "YES\n";
	}
}