#include<bits/stdc++.h>
using namespace std;
int n, res;
int tr[20005][26];
int e[20005], fail[20005];
inline void insert(string s, int x)
{
	int head = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(!tr[head][s[i] - 'a'])
			tr[head][s[i] - 'a'] = ++res;
		head = tr[head][s[i] - 'a'];
	}
	e[head] = x;
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
int T, ans, h[1005];
string s[1005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(cin >> n)
	{
		if(!n) break;
		res = 0;
		memset(tr, 0, sizeof(tr));
		memset(h, 0, sizeof(h));
		memset(e, 0, sizeof(e));
		memset(fail, 0, sizeof(fail));
		for(int i = 1; i <= n; i++)
		{
			cin >> s[i];
			insert(s[i], i);
		}
		build();
		string t;
		cin	>> t;
		int p = 0;
		for(int i = 0; i < t.size(); i++)
		{
			char x = t[i];
			p = tr[p][x - 'a'];
			for(int j = p; j; j = fail[j]) h[e[j]]++;
		}
		int maxn = 0;
		for(int i = 1; i <= n; i++)
			maxn = max(maxn, h[i]);
		cout << maxn << '\n';
		for(int i = 1; i <= n; i++)
			if(h[i] == maxn)
				cout << s[i] << '\n';
	}
	return 0;
}