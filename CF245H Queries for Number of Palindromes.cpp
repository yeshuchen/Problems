#include<bits/stdc++.h>
using namespace std;
int T, l, r;
bool is[5005][5005];
int f[5005][5005];
char s[100005];
signed main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = 1; i <= n; i++)
		f[i][i] = 1;
	s[0] = '0';
	for(int i = 1; i <= n; i++)
	{
		int p = 1;
		while(s[i - p] == s[i + p]) p++;
		for(int j = 1; j < p; j++)
			is[i - j][i + j] = 1;
		if(s[i] == s[i + 1])
		{
			is[i][i + 1] = 1;
			p = 1;
			while(s[i - p] == s[i + p + 1]) p++;
			for(int j = 1; j < p; j++)
				is[i - j][i + j + 1] = 1;
		}
	}
	for(int len = 2; len <= n; len++)
		for(int i = 1; i <= n; i++)
		{
			int j = i + len - 1;
			if(j > n) break;
			f[i][j] = f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1];
			if(is[i][j])
				f[i][j]++;
		}
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &l, &r);
		printf("%d\n", f[l][r]);
	}
	return 0;
}
/*
假设我要把两个区间的回文串数量合并在一起
有且仅有一种可能，两个区间合并后在中间产生了回文串
预处理出以任意一个节点作为回文串中心
*/