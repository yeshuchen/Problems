#include<bits/stdc++.h>
using namespace std;
int T, x, k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> x >> k;
		if(x % k != 0) cout << 1 << '\n' << x << '\n';
		else cout << 2 << '\n' << 1 << ' ' << x - 1 << '\n';
	}
	return 0;
}