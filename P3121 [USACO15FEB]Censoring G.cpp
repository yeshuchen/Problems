#include<bits/stdc++.h>
using namespace std;
int tr[100005][26];
int e[100005], res;
inline void insert(string s, int x)
{
	int head = 0;
	for(int i = 0; i < s.size(); i++)
	{
		char x = s[i] - 'a';
		if(!tr[head][x]) tr[head][x] = ++res;
		head = tr[head][x];
	}
	e[head] = x;
}
int fail[100005];
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
int n;
string s, t[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> t[i];
		insert(t[i], i);
	}
	build();
	int p = 0;
	stack<int> s1; s1.push(0);
	stack<char> s2;
	for(int i = 0; i < s.size(); i++)
	{
		p = tr[p][s[i] - 'a'];
		s1.push(p); s2.push(s[i]);
		if(e[p])
		{
			for(int k = 0; k < t[e[p]].size(); k++)
				s1.pop(), s2.pop();
			p = s1.top();
		}	
	}
	stack<char> s3;
	while(!s2.empty()) s3.push(s2.top()), s2.pop();
	while(!s3.empty()) cout << s3.top(), s3.pop();
	return 0;
}