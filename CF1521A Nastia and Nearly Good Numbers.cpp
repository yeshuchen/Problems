#include<bits/stdc++.h>
#define int long long
using namespace std;
int T, a, b;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> a >> b;
		if(b == 1) {cout << "NO\n"; continue;}
		cout << "YES\n";
		if(b == 2) cout << a << ' ' << 3 * a << ' ' << 4 * a << '\n';
		else cout << a << ' ' << (b - 1) * a << ' ' << a * b << '\n';
	}
	return 0;
}