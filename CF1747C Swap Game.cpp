#include<bits/stdc++.h>
using namespace std;
int T, n, w;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int minn = INT_MAX;
		cin >> n;
		cin >> w;
		for(int i = 2, v; i <= n; i++)
			cin >> v, minn = min(minn, v);
			if(minn < w) cout << "Alice\n";
			else cout << "Bob\n";
	}
	return 0;
}