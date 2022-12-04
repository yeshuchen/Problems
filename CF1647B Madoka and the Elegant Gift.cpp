#include<bits/stdc++.h>
using namespace std;
int T, res;
bool vis[105][105];
char c[105][105];
inline void dfs(int x, int y)
{
	vis[x][y] = 1;
	if(c[x + 1][y] == '1' && !vis[x + 1][y]) dfs(x + 1, y);
	if(c[x][y + 1] == '1' && !vis[x][y + 1]) dfs(x, y + 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		memset(c, '0', sizeof(c));
		memset(vis, 0, sizeof(vis));
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> c[i][j];
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				if(c[i][j] == '1' && !vis[i][j])
				{
					int p1 = i, p2 = j;
					dfs(i, j);
					while(c[p1][j] == '1') p1++;
					while(c[i][p2] == '1') p2++;
					for(int k = i; k < p1; k++)
						for(int l = j; l < p2; l++)
							if(c[k][l] == '0')
							{
								cout << "NO\n";
								goto end;
							}
					for(int k = i; k < p1; k++)
						if(c[k][j - 1] == '1' || c[k][p2] == '1')
						{
							cout << "NO\n";
							goto end;
						}
					for(int k = j; k < p2; k++)
						if(c[i - 1][k] == '1' || c[p1][k] == '1')
						{
							cout << "NO\n";
							goto end;
						}
				}
		cout << "YES\n";
		end:;
	}
	return 0;
}