#include<bits/stdc++.h>
using namespace std;
int l, r;
int c[50][50];
inline void prepare()
{
	c[0][0] = 1;
	for(int i = 1; i <= 32; i++)
	{
		c[i][0] = c[i - 1][0];
		for(int j = 1; j <= i; j++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}
}
inline int solve(int x)
{
	int di = 0;
	for(int i = 32; i >= 0; i--)
		if(x & (1ll << i))
		{
			di = i;
			break;
		}
	int cnt = 0, ans = 0;
	for(int i = di - 1; i >= 0; i--)
	{
		if(x & (1ll << i))
		{
			cnt++;
			if(cnt + i >= (di + 2) / 2) ans++;
			for(int k = max((di + 2) / 2 - cnt, 0); k < i; k++)
				ans = ans + c[i][k];
			cnt--;
		}
		else cnt++;
	}	
	for(int i = di - 1; i >= 0; i--)
		for(int j = (i + 2) / 2; j <= i; j++)
			ans = ans + c[i][j];
	return ans + (cnt >= (di + 2) / 2);
}
int main()
{  
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> l >> r;
	prepare();
	cout << solve(r) - solve(l - 1);
	return 0;
}