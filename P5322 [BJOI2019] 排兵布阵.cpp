#include<bits/stdc++.h>
using namespace std;
int s, n, m;
int p[105][105];
int temp[105][10005];
int dp[10005];
int main()
{
	cin >> s >> n >> m;
	for(int i = 1; i <= s; i++)
		for(int j = 1; j <= n; j++)
			cin >> p[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= s; j++)
		{
			int pos = 2 * p[j][i] + 1, spd = 0;
			for(int k = 1; k <= s; k++)
				if(pos > 2 * p[k][i])
					spd += i;
			temp[i][pos] = spd;
		}
	for(int i = 1; i <= n; i++)
		for(int j = m; j; j--)
			for(int k = 1; k <= s; k++)
			{
				if(2 * p[k][i] + 1 > j) continue;
				int spd = temp[i][2 * p[k][i] + 1];
				dp[j] = max(dp[j], dp[j - 2 * p[k][i] - 1] + spd);
			}
	cout << dp[m];
	return 0;
}
/*
设f[i][j]表示向前i个城堡派遣j个士兵的最大收益
预处理出向第 i 个城堡派遣 j 个士兵的收益
然后就是分组背包
一共有n组，每组s个物品，容量为m
。。。寄
我们需要更加高效的方法
考虑一下，显然，你派的士兵越多，收益越高，在一定的区间内，收入不会有变化
这样，我们可以把物品优化至s个，可以通过该题
*/