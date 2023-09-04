#include<bits/stdc++.h>
using namespace std;
int T, n;
int f[500];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int ans = 0, res = 0;
		cin >> n;
		memset(f, 0, sizeof(f)); f[0] = 1;
		for(int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			res ^= x;
			for(int i = 0; i < 256; i++)
				if(f[i]) ans = max(ans, res ^ i);
			f[res] = 1;
		}
		cout << ans << '\n';
	}
	return 0;
}