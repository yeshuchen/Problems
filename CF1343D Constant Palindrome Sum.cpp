#include<bits/stdc++.h>
using namespace std;
int T, n, k;
int a[400005];
int d[400005], t[400005], u[400005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> k;
		for(int i = 1; i <= 2 * k + 2; i++) d[i] = t[i] = u[i] = 0;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n / 2; i++)
			d[a[i] + a[n - i + 1]]++, t[max(a[i], a[n - i + 1]) + k + 1]++, u[min(a[i], a[n - i + 1])]++;
		for(int i = 1; i <= 2 * k; i++)
			t[i] += t[i - 1];
		for(int i = 2 * k; i; i--)
			u[i] += u[i + 1];
		int minn = INT_MAX;
		for(int i = 1; i <= 2 * k; i++) minn = min(minn, n / 2 - d[i] + t[i] + u[i]);
		cout << minn << '\n';
	}
	return 0;
}