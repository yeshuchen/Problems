#include<bits/stdc++.h>
using namespace std;
int T;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for(int c = 1; c <= T; c++)
	{
		long long x1, x2, y1, y2;
		cout << "Case " << c << ": ";
		cin >> x1 >> y1 >> x2 >> y2;
		long long dis1 = abs(x1 - x2), dis2 = abs(y1 - y2);
		cout << __gcd(dis1, dis2) + 1 << '\n';
	}
	return 0;
}