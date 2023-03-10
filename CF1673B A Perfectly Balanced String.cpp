#include<bits/stdc++.h>
using namespace std;
int n, T;
char s[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int cnt = 0;
		bool v[200];
		memset(v, 0, sizeof(v));
		cin >> s + 1;
		int n = strlen(s + 1);
		for(int i = 1; i <= n; i++)
			if(!v[s[i]]) cnt++, v[s[i]] = 1;
		memset(v, 0, sizeof(v));
		int res = 0;
		for(int i = 1; i <= cnt; i++)
			if(!v[s[i]]) res++, v[i] = 1;
		if(res != cnt) {cout << "NO\n"; continue;}
		for(int i = cnt + 1; i <= n; i++)
			if(s[i] != s[i - cnt])
			{
				cout << "NO\n";
				goto here;
			}
		cout << "YES\n";
		here:;
	}
	return 0;
}