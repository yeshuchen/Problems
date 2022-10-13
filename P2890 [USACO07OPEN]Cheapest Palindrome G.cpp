#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, m;
char s[10005];
ll f[2005][2005];
int add[10005], del[10005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> m >> n;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	for(int i = 1; i <= m; i++)
	{
		char ch; int x, y;
		cin >> ch >> x >> y;
		add[ch] = x; del[ch] = y;
	}
	for(int i = 1; i <= m; i++)
		f[i][i] = 0;
	for(int len = 2; len <= n; len++)
		for(int i = 1; i <= n; i++)
		{
			int j = i + len - 1;
			if(s[i] == s[j]) f[i][j] = f[i + 1][j - 1];
			else
			{
				f[i][j] = INT_MAX;
				f[i][j] = min(f[i][j], f[i + 1][j] + add[s[i]]);
				f[i][j] = min(f[i][j], f[i + 1][j] + del[s[i]]);
				f[i][j] = min(f[i][j], f[i][j - 1] + add[s[j]]);
				f[i][j] = min(f[i][j], f[i][j - 1] + del[s[j]]);
			}
		}
	cout << f[1][n];
	return 0;
}
/*
我们得推翻原本的思路，因为你不能确定两边的结构
所以，考虑设 f[i. j] 为通过增添字符使得 [i, j] 相同的最小成本
显然，我们可以在左边加字符和右边加字符
我们也可以在左边删字符和右边删字符
而且我们也只能由这四个状态转移而来
综上，解法就不难想出了
*/