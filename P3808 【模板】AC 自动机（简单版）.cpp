#include<bits/stdc++.h>
using namespace std;
int n, res;
int tr[1000005][27];
int e[1000005], fail[1000005];
inline void insert(string s)
{
	int head = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(!tr[head][s[i] - 'a'])
			tr[head][s[i] - 'a'] = ++res;
		head = tr[head][s[i] - 'a'];
	}
	e[head]++;
}
inline void build()
{
	queue<int> q;
	for(int i = 0; i < 26; i++)
		if(tr[0][i])
			q.push(tr[0][i]);
	while(!q.empty())
	{
		int k = q.front(); q.pop();
		for(int i = 0; i < 26; i++)
		{
			if(tr[k][i])
			{
				fail[tr[k][i]] = tr[fail[k]][i];
				q.push(tr[k][i]);
			}
			else tr[k][i] = tr[fail[k]][i];
		}
	}
}
int ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		insert(s);
	}
	build();
	string t;
	cin >> t;
	int p = 0;
	for(int i = 0; i < t.size(); i++)
	{
		char x = t[i];
		p = tr[p][x - 'a'];
		for(int j = p; j && e[j] != -1; j = fail[j]) ans += e[j], e[j] = -1;
	}
	cout << ans;
	return 0;
}