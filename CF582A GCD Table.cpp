#include<bits/stdc++.h>
using namespace std;
int n, res = 2;
int a[505 * 505];
int ans[505];
map<int, int> c;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n * n; i++)
		cin >> a[i];	
	if(n == 1) {cout << a[1]; return 0;}	
	sort(a + 1, a + n * n + 1);
	ans[1] = a[n * n]; ans[2] = a[n * n - 1];
	c[__gcd(ans[1], ans[2])] = 2;
	for(int i = n * n - 2; i; i--)
	{
		if(c[a[i]]) c[a[i]]--;
		else
		{
			ans[++res] = a[i];
			for(int i = 1; i < res; i++)
				c[__gcd(ans[i], ans[res])] += 2;
		}
	}
	for(int i = 1; i <= res; i++) cout << ans[i] << ' ';
	return 0;
}