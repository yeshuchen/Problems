#include<bits/stdc++.h>
using namespace std;
int T, n, k;
int a[100005], vis[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> k; for(int i = 0; i <= n; i++) vis[i] = 0;
		for(int i = 1; i <= n; i++)
			cin >> a[i], vis[a[i]] = 1;
		for(int i = 0; i <= n; i++)
			if(!vis[i])
			{
				a[++n] = i;
				break;
			}
		k %= n;
		for(int i = n - k + 1; i <= n; i++) cout << a[i] << ' ';
		for(int i = 1; i < n - k; i++) cout << a[i] << ' ';
		cout << '\n';
	}
	return 0;
}