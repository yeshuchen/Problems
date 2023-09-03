#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
int n, m, res, a[255];
char s[N], t[100005][105];
int tr[N][4];
inline void insert(int id)
{
	int len = strlen(t[id] + 1), p = 0;
	for(int i = 1; i <= len; i++)
	{
		int x = a[t[id][i]];
		if(!tr[p][x]) tr[p][x] = ++res;
		p = tr[p][x];
	}
}
int fail[N];
inline void build()
{
	queue<int> q;
	for(int i = 0; i < 4; i++)
		if(tr[0][i]) q.push(tr[0][i]);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = 0; i < 4; i++)
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
int vis[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; a['S'] = 0; a['W'] = 1; a['E'] = 2; a['N'] = 3;
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= m; i++)
	{
		cin >> t[i] + 1;
		insert(i);
	} 
	int p = 0; build();
	for(int i = 1; i <= n; i++)
	{
		p = tr[p][a[s[i]]];
		for(int j = p; j; j = fail[j])
		{
			if(vis[j]) break;
			vis[j] = 1;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		int ans = 0;
		p = 0; int len = strlen(t[i] + 1);
		for(int j = 1; j <= len; j++)
		{
			p = tr[p][a[t[i][j]]];
			if(vis[p]) ans = j;
		}
		cout << ans << '\n';
	}
	return 0;
}