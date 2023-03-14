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
		int x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		if(x1 == x2 && y2 == y3 || x3 == x2 && y2 == y1 || x2 == x3 && y3 == y1 || x1 == x3 && y3 == y2 || x2 == x1 && y1 == y3 || x3 == x1 && y1 == y2) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}