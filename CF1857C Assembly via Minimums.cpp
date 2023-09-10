#include<bits/stdc++.h>
using namespace std;
int T, n, a[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n * (n - 1) / 2; i++)
			cin >> a[i];
		sort(a + 1, a + n * (n - 1) / 2 + 1);
		for(int i = 1, p = n - 1; i <= n * (n - 1) / 2; i += p, p--)
			cout << a[i] << ' ';
		cout << (int)1e9;
		cout << '\n';
	}	
	return 0;
}