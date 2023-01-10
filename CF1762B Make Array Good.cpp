#include<bits/stdc++.h>
using namespace std;
int T, a[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		cout << n << '\n';
		for(int i = 1; i <= n; i++)
		{
			int base = 1;
			for(int j = 1; base <= a[i]; j++)
				base *= 2;
			cout << i << ' ' << base - a[i] << '\n';
		}
	}
	return 0;
}