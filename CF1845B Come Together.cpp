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
		int xa, ya, xb, yb, xc, yc;
		cin >> xa >> ya >> xb >> yb >> xc >> yc;
		cout << (abs(xb - xa) + abs(yb - ya) + abs(xc - xa) + abs(yc - ya) - abs(xb - xc) - abs(yb - yc) + 2) / 2 << '\n';
	}
	return 0;
}