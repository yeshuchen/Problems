#include<bits/stdc++.h>
using namespace std;
int cnt, tot, ans = -1;
int lcnt[10], temp[1001];
int a[10][10];
int vis[3][10][10];
const int p[10][10]=
{{0,0,0,0,0,0,0,0,0,0},
{0,6,6,6,6,6,6,6,6,6},
{0,6,7,7,7,7,7,7,7,6},
{0,6,7,8,8,8,8,8,7,6},
{0,6,7,8,9,9,9,8,7,6},
{0,6,7,8,9,10,9,8,7,6},
{0,6,7,8,9,9,9,8,7,6},
{0,6,7,8,8,8,8,8,7,6},
{0,6,7,7,7,7,7,7,7,6},
{0,6,6,6,6,6,6,6,6,6}};
int go(int x,int y){return ((x - 1) / 3 * 3 + (y - 1) / 3 + 1);}
void dfs(int step)
{
	if(step > tot)
	{
		int res = 0;
		for(int i = 1; i <= 9; i++)
			for(int j = 1; j <= 9; j++)
				res += p[i][j] * a[i][j];
		ans = max(ans, res);
		return;
	}
	int x = temp[step] / 10, y = temp[step] % 10;
	for(int i = 1; i <= 9; i++)
	{
		if(!vis[0][x][i] && !vis[1][y][i] && !vis[2][go(x, y)][i])
		{
			vis[0][x][i] = vis[1][y][i] = vis[2][go(x, y)][i] = 1;
			a[x][y] = i;
			dfs(step + 1);
			vis[0][x][i] = vis[1][y][i] = vis[2][go(x, y)][i] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	lcnt[0] = INT_MAX;
	for(int i = 1; i <= 9; i++)
		lcnt[i] = 9;
	for(int i = 1; i <= 9; i++)
		for(int j = 1; j <= 9; j++)
		{
			cin >> a[i][j];
			if(a[i][j])lcnt[i]--;
			vis[0][i][a[i][j]] = 1;
			vis[1][j][a[i][j]] = 1;
			vis[2][go(i,j)][a[i][j]] = 1;
		}
	for(int i = 1; i <= 9; i++)
	{
		int C = 0;
		for(int j = 1; j <= 9; j++)
			if(lcnt[j] && lcnt[j] < lcnt[C])
				C = j;
		if(!C) break;
		for(int j = 1; j <= 9; j++)
			if(!a[C][j])
				temp[++tot] = C * 10 + j;
		lcnt[C] = 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}