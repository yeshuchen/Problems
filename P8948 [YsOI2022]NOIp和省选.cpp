#include<bits/stdc++.h>
using namespace std;
int n, c;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> c;
	cout << 200 << ' ' << 500 << '\n';
	for(int i = 2; i <= n; i++)
	{
		cin >> c;
		if(c < 1000)
		{
			if(c & 1) cout << 1 << ' ' << (c - 5) / 2 << '\n';
			else cout << 0 << ' ' << c / 2 << '\n';
		}
		else if(c == 1000) cout << 200 << ' ' << 0 << '\n';
		else
		{
			if(c & 1) cout << 199 << ' ' << (c - 995) / 2 << '\n';
			else cout << 200 << ' ' << (c - 1000) / 2 << '\n';
		}
	}
	return 0;
}