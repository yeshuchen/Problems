#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, mod = 10007;
int n, m;
char s[N];
int res;
int tr[N][26], vis[N << 2];
int fail[N << 2];
inline void insert(char *s)
{
	int len = strlen(s + 1), rt = 0;
	for(int i = 1; i <= len; i++)
	{
		int x = s[i] - 'A';
		if(!tr[rt][x])
			tr[rt][x] = ++res;
		rt = tr[rt][x];
	}
	vis[rt] = 1;
}
inline void build()
{
	queue<int> q;
	for(int i = 0; i < 26; i++)
		if(tr[0][i])
			q.push(tr[0][i]);
	while(!q.empty())
	{
		int x = q.front(); q.pop(); vis[x] |= vis[fail[x]];
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
int dp[105][N << 2];
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
	build(); dp[0][0] = 1;
	for(int i = 1; i <= m; i++)
		for(int j = 0; j <= res; j++)
			for(int k = 0; k < 26; k++)
				if(!vis[tr[j][k]])
					dp[i][tr[j][k]] = (dp[i][tr[j][k]] + dp[i - 1][j]) % mod;
	// for(int i = 1; i <= n; i++, cout << '\n')
	// 	for(int j = 0; j <= res; j++)
	// 		cout << dp[i][j] << ' ';
	int ans = 1;
	for(int i = 1; i <= m; i++)
		ans = ans * 26 % mod;
	for(int i = 0; i <= res; i++)
		ans = (ans - dp[m][i] + mod) % mod;
	cout << ans;
	return 0;
}
