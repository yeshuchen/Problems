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
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(y1 > y2) {cout << -1 << '\n'; continue;}
		x2 = x2 - (y2 - y1);
		if(x2 > x1) {cout << -1 << '\n'; continue;}
		cout << (x1 - x2) + (y2 - y1) << '\n';
	}
	return 0;
}