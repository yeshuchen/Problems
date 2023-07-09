#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, tot;
int d[100005];
int c1[100005], c2[100005];
int a[100005], temp[100005];
inline void add(int* c, int x)
{
	while(x <= n)
	{
		c[x]++;
		x += (x & -x);
	}
}
inline int ask(int* c, int x)
{
	int res = 0;
	while(x)
	{
		res += c[x];
		x -= (x & -x);
	}
	return res;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], temp[++tot] = a[i];
	sort(temp + 1, temp + tot + 1);
	tot = unique(temp + 1, temp + tot + 1) - temp - 1;
	for(int i = 1; i <= n; i++)
		a[i] = lower_bound(temp + 1, temp + tot + 1, a[i]) - temp;
	for(int i = n; i >= 1; i--)
	{
		d[i] += ask(c1, a[i] - 1);
		add(c1, a[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		d[i] += ask(c2, n) - ask(c2, a[i]);
		add(c2, a[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans += d[i] * (d[i] + 1) / 2;
	cout << ans;
	return 0;
}