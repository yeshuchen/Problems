#include<bits/stdc++.h>
using namespace std;
int T, n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		cout << n << ' ';
		for(int i = 2; i <= n; i++)
			cout << i - 1 << ' ';
		cout << '\n';
	}
	return 0;
}