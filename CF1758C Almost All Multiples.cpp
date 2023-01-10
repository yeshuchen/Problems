#include<bits/stdc++.h>
using namespace std;
int T;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int n, k;
		cin >> n >> k;
		if(n % k != 0) {cout << -1 << '\n'; continue;}
		cout << k << ' '; 
		for(int i = 2; i < n; i++)
		{
			if(i == k)
			{
				for(int j = 2; i * j <= n; j++)
					if(n % (i * j) == 0 && i * j != n)
					{
						k *= j;
						cout << i * j << ' ';
						break;
					}
				if(i == k) cout << n << ' ';
			}
			else cout << i << ' ';
		}
		cout << 1 << '\n';
	}
	return 0;
}