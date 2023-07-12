#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int x = 1, y = 1, d, n, m;
		cin >> n >> m;
		cout << "? " << 1 << ' ' << 1 << endl;
		cout << flush;
		cin >> d;
		x += d; y += d;
		x = min(x, n); y = min(y, m);
		cout << "? " << x << ' ' << y << endl;
		cout << flush;
		cin >> d;
		if(!d)
		{
			cout << "! " << x << ' ' << y << endl;
			cout << flush;
			continue;
		}
		y -= d;
		cout << "? " << x << ' ' << y << endl;
		cout << flush;
		cin >> d;
		if(!d) cout << "! " << x << ' ' << y << endl, cout << flush;
		else cout << "! " << x - d << ' ' << y + d << endl, cout << flush;
	}
	return 0;
}