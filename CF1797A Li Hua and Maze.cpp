#include<bits/stdc++.h>
using namespace std;
inline int check(int x, int y, int n, int m)
{
	if(x == 1 && y == 1 || x == 1 && y == m || x == n && y == 1 || x == n && y == m) return 2;
	else if(x == 1 || y == 1 || x == n || y == m) return 3;
	return 4;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n, m, x1, y1, x2, y2;
		cin >> n >> m;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << min(check(x1, y1, n, m), check(x2, y2, n, m)) << '\n';
	}
	return 0;
}