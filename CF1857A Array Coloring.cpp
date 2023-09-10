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
		int x, sum = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> x, sum ^= x;
		if(sum & 1) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}