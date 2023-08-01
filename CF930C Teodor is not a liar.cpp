#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m;
int c[N], s[N];
int f1[N], f2[N];
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		c[l]++; c[r + 1]--;
	}
	for(int i = 1; i <= m; i++) c[i] += c[i - 1];
	int len = 0;
	s[++len] = c[1]; f1[1] = 1;
	for(int i = 2; i <= m; i++)
	{
		if(c[i] >= s[len]) s[++len] = c[i], f1[i] = len;
		else
		{
			int p = upper_bound(s + 1, s + len + 1, c[i]) - s;
			s[p] = c[i]; f1[i] = p;
		}
	}
	len = 0;
	s[++len] = c[m]; f2[m] = 1;
	for(int i = m - 1; i; i--)
	{
		if(c[i] >= s[len]) s[++len] = c[i], f2[i] = len;
		else
		{
			int p = upper_bound(s + 1, s + len + 1, c[i]) - s;
			s[p] = c[i]; f2[i] = p;
		}
	}
	int ans = 0;
	for(int i = 1; i <= m; i++)
		ans = max(ans, f1[i] + f2[i] - 1);
	cout << ans;
	return 0;
}