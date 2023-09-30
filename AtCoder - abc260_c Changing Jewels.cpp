#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, x, y;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> x >> y;
	int red = 1, blue = 0;
	for(int i = 1; i < n; i++)
	{
		int tmp = red;
		red += red * x + blue;
		blue = (tmp * x + blue) * y;
	}
	cout << blue;
	return 0;
}