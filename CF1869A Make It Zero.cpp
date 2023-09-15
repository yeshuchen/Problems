#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int T, n;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		if(!(n & 1)) {cout << 2 << '\n' << 1 << ' ' << n << '\n' << 1 << ' ' << n << '\n';}
		else {cout << 4 << '\n' << 1 << ' ' << n << '\n' << 1 << ' ' << 2 << '\n' << 2 << ' ' << 3 << '\n' << 1 << ' ' << n << '\n';}
	}
	return 0;
}