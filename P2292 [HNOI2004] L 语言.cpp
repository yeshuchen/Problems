#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, res;
char s[N << 4];
int vis[N], ans, maxl;
int tr[N][26];
inline void insert(char *s)
{
	int len = strlen(s + 1), p = 0;
	maxl = max(maxl, len);
	for(int i = 1; i <= len; i++)
	{
		int x = s[i] - 'a';
		if(!tr[p][x]) tr[p][x] = ++res;
		p = tr[p][x];
	}
	vis[p] = len;
}
int fail[N];
inline void build()
{
	queue<int> q;
	for(int i = 0; i < 26; i++)
		if(tr[0][i]) q.push(tr[0][i]);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = 0; i < 26; i++)
		{
			if(!tr[x][i]) tr[x][i] = tr[fail[x]][i];
			else
			{
				fail[tr[x][i]] = tr[fail[x]][i];
				q.push(tr[x][i]);
			}
		}
	}
}
vector<int> v[N << 4];
int f[N << 4];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> s + 1;
		insert(s);
	}
	build(); f[0] = 1;
	for(int i = 1; i <= res; i++)
		for(int j = i; j; j = fail[j])
			if(vis[j]) v[i].push_back(vis[j]);
	for(int i = 1; i <= m; i++)
	{
		cin >> s + 1; ans = 0;
		int len = strlen(s + 1), p = 0;
		for(int i = 1; i <= len; i++)
		{
			f[i] = 0; if(ans + maxl < i) break;
			p = tr[p][s[i] - 'a'];
			for(int j = 0; j < v[p].size(); j++)
			{
				f[i] |= f[i - v[p][j]];
				if(f[i]) break;
			}
			if(f[i]) ans = i;
		}
		cout << ans << '\n';
	}
	return 0;
}