#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int T, n, a[N];
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
		cout << 1 << ' ' << n << '\n';
	}
	return 0;
}