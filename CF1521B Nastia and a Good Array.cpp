#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int p1 = 1000000007, p2 = 1000000009;
int T, n;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		cout << n - 1 << '\n';
		for(int i = 1; i < n; i++)
		{
			int x = ((i & 1) ? p1 : p2);
			cout << i << ' ' << i + 1 << ' ' << x << ' ' << min(a[i], a[i + 1]) << '\n';
			a[i + 1] = min(a[i], a[i + 1]);
		}
	}
	return 0;
}