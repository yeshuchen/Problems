#include<bits/stdc++.h>
using namespace std;
int n, res;
bool ans[1000005];
int a[1000005], q[1000005];
int p[1000005], d[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> p[i] >> d[i], p[i + n] = p[i], d[i + n] = d[i];
	for(int i = 1; i <= 2 * n; i++)
	{
		a[i] = res;
		res += p[i];
		res -= d[i];
	}
	int h = 1, t = 0;
	for(int i = 1; i <= 2 * n; i++)
	{
		while(q[h] <= i - n && h <= t) h++;
		while(a[q[t]] > a[i] && h <= t) t--;
		q[++t] = i;
		if(i > n) ans[i - n] |= (a[q[h]] - a[i - n] >= 0);
	}
	res = 0;
	for(int i = 2 * n; i; i--)
	{
		a[i] = res;
		res += p[i];
		res -= d[i - 1];
	}
	for(int i = 1; i <= 2 * n; i++) q[i] = 0;
	h = 1, t = 0;
	for(int i = 2 * n; i; i--)
	{
		while(q[h] >= i + n && h <= t) h++;
		while(a[q[t]] > a[i] && h <= t) t--;
		q[++t] = i;
		if(i <= n) ans[i] |= (a[q[h]] - a[i + n] >= 0);
	}
	for(int i = 1; i <= n; i++)
	{
		if(ans[i]) cout << "TAK\n";
		else cout << "NIE\n";
	}
	return 0;
}