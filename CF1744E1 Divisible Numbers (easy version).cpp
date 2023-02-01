#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for(int i = a + 1; i <= c; i++)
		{
			int x = a * b / __gcd(a * b, i);
			int y = (b / x + 1) * x;
			if(y <= d)
			{
				cout << i << ' ' << y << '\n';
				goto here;
			}	
		}
		cout << -1 << ' ' << -1 << '\n';
		here:;
	}
	return 0;
}