#include<bits/stdc++.h>
using namespace std;
extern "C" bool move_to(char position);
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
char ch[4] = {'W', 'A', 'S', 'D'};
int m[505][505];
inline void dfs(int x, int y)
{
	m[x][y] = 1;
	for(int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if(~m[nx][ny]) continue;
		bool tmp = move_to(ch[i]);
		if(!tmp)
		{
			m[nx][ny] = 0;
			continue;
		}
		dfs(nx, ny);
		if(i & 1) move_to(ch[4 - i]);
		else move_to(ch[2 - i]);
	}
}
extern "C" string find_out_map(int X, int Y, int n)
{
	memset(m, -1, sizeof(m)); 
	dfs(X, Y);
	string ans = "";
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(m[i][j] == 1) ans += '0';
			else ans += '1';
		}
	return ans;
}
