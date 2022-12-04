#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n;
int a[N], l[N], r[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int minn = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		cout << n - 1 << '\n';
		if(n == 1) continue;
		cout << 1 << ' ' << n << '\n';
		for(int i = 2; i < n; i++)
		{
			if(a[i] % 2 == a[1] % 2)
				cout << i << ' ' << n << '\n';
			else cout << 1 << ' ' << i << '\n';
		}
	}
	return 0;
}