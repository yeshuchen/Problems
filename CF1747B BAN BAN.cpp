#include<bits/stdc++.h>
using namespace std;
int T, n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		cout << (n + 1) / 2 << '\n';
		for(int i = 1; i <= n / 2; i++)
			cout << (i - 1) * 3 + 2 << ' ' << (n - i) * 3 + 3 << '\n';
		if(n & 1) cout << n / 2 * 3 + 2 << ' ' << n / 2 * 3 + 3 << '\n';
	}
	return 0;
}