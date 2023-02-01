#include<bits/stdc++.h>
using namespace std;
int n, res;
int vis[2000005];
int tr[2000005][26];
inline void insert(string s)
{
	int head = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(!tr[head][s[i] - 'a']) tr[head][s[i] - 'a'] = ++res;
		head = tr[head][s[i] - 'a'];
	}
	vis[head]++;
}
int ans, f[2000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		insert(s);
	}
	for(int i = res; i >= 0; i--)
	{
		f[i] = vis[i];
		int mx1 = 0, mx2 = 0;
		for(int j = 0; j < 26; j++)
		{
			if(!vis[tr[i][j]]) continue;
			f[i]++;
			if(f[tr[i][j]] - 1 > mx1) mx2 = mx1, mx1 = f[tr[i][j]] - 1;
			else if(f[tr[i][j]] - 1 > mx2) mx2 = f[tr[i][j]] - 1;
		}
		f[i] += mx1; ans = max(ans, f[i] + mx2);
	}
	cout << ans;
	return 0;
}