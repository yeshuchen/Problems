#include<bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5;
int tot, temp[N];
int n, op[N], f[N];
int x[N], y[N], w[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	temp[++tot] = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> op[i];
		if(op[i] == 1)
		{
			cin >> x[i] >> y[i] >> w[i];
			temp[++tot] = x[i]; temp[++tot] = x[i] - 1;
			temp[++tot] = y[i]; temp[++tot] = y[i] + 1;
		}
		else
		{
			cin >> x[i] >> w[i];
			temp[++tot] = x[i];
			temp[++tot] = x[i] - 1;
			temp[++tot] = x[i] + 1;
		}
	}
	sort(temp + 1, temp + tot + 1);
	tot = unique(temp + 1, temp + tot + 1) - temp - 1;
	for(int i = 1; i <= n; i++)
	{
		x[i] = lower_bound(temp + 1, temp + tot + 1, x[i]) - temp;
		y[i] = lower_bound(temp + 1, temp + tot + 1, y[i]) - temp;
	}
	for(int i = 1; i <= n; i++)
	{
		if(op[i] == 1)
		{
			f[x[i]] ^= w[i];
			f[y[i] + 1] ^= w[i];
		}
		if(op[i] == 2) f[x[i]] ^= w[i], f[x[i] + 1] ^= w[i];
		if(op[i] == 3) f[1] ^= w[i], f[x[i]] ^= w[i], f[x[i] + 1] ^= w[i];
	}
	int maxn = 0;
	for(int i = 1; i <= tot; i++)
	{
		f[i] ^= f[i - 1];
		if(f[i] == f[maxn])
			if(abs(temp[i]) < abs(temp[maxn]) || abs(temp[i]) == abs(temp[maxn]) && temp[i] > temp[maxn]) maxn = i;
		if(f[i] > f[maxn]) maxn = i;
	}
	cout << f[maxn] << ' ' << temp[maxn];
	return 0;
}