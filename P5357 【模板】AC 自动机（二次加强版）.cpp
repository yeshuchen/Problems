#include<bits/stdc++.h>
using namespace std;
int n, res;
int vis[200005];
vector<int> e[200005];
int tr[200005][26], fail[200005];
inline void insert(string s, int x)
{
	int head = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(!tr[head][s[i] - 'a'])
			tr[head][s[i] - 'a'] = ++res;
		head = tr[head][s[i] - 'a'];
	}
	vis[x] = head;
}
int in[200005];
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
				in[tr[fail[k]][i]]++;
				q.push(tr[k][i]);
			}
			else tr[k][i] = tr[fail[k]][i];
		}
	}
}
int h[200005];
inline void topo()
{
	queue<int> q;
	for(int i = 1; i <= res; i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		int y = fail[x]; in[y]--;
		h[y] += h[x];
		if(!in[y]) q.push(y);
	}
}
string s[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
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
		h[p]++;
	}
	topo();
	for(int i = 1; i <= n; i++)
		cout << h[vis[i]] << '\n';
	return 0;
}