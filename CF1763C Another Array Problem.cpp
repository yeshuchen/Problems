#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int T, n;
long long a[N];
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
		if(n == 2) cout << max(a[1] + a[2], 2 * abs(a[1] - a[2])) << '\n';
		else if(n == 3) cout << max({a[1] + a[2] + a[3], 3 * a[1], 3 * a[3], 3 * abs(a[2] - a[1]), 3 * abs(a[2] - a[3])}) << '\n';
		else
		{
			sort(a + 1, a + n + 1);
			cout << a[n] * n << '\n';
		}
	}
	return 0;
}