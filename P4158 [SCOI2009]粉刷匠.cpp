#include<bits/stdc++.h>
using namespace std;
int n, m, t;
int p[51][2];
int c[51][51];
int f[2][51][2005];
int dp[2505];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> t;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			char ch;
			cin >> ch;
			c[i][j] = ch - '0';
		}
	for(int i = 1; i <= n; i++)
	{
		memset(f, 0, sizeof(f));
		int red = 0, blue = 0;
		for(int j = m; j; j--)
		{
			if(c[i][j] == 0) red++;
			else blue++;
			p[j][0] = red; p[j][1] = blue;
		}		
		for(int j = 0; j <= m; j++)
			f[0][j][1] = p[j][0], f[1][j][1] = p[j][1];
		for(int k = 2; k <= t; k++)
		{
			for(int j = k; j <= m; j++)
			{
				for(int l = 1; l <= j; l++)
				{
					f[0][j][k] = max(f[0][j][k], f[1][l][k - 1] + p[j][0] - p[j][1]);
					f[1][j][k] = max(f[1][j][k], f[0][l][k - 1] + p[j][1] - p[j][0]);
				}
			}
		}
		for(int v = t; v >= i; v--)
		{
			for(int k = 1; k <= v; k++)
			{
				for(int j = k; j <= m; j++)
					dp[v] = max(dp[v], dp[v - k] + max(f[0][j][k], f[1][j][k]));
			}
		}
	}
	cout << dp[t];
	return 0;
}
/*
显然有一个结论，从这个位置开始刷，应该直接刷到底
而且颜色一定相间。
可以通过预处理得出我们所需要的信息
然后就是分组背包板子
省略行号
f[j][k][color] 表示从位置j开始使用颜色color花费k次粉刷一路刷到底的最大格子数
*/