#include<bits/stdc++.h>
using namespace std;
int T;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int n, minn = INT_MAX, maxn = 0;
		cin >> n;
		for(int i = 1, x; i <= n; i++)
			cin >> x, minn &= x, maxn |= x;
		cout << maxn - minn << '\n';
	}
	return 0;
}