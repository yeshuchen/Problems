#include<bits/stdc++.h>
using namespace std;
int T;
int a[1005][1005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				cin >> a[i][j];
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(a[n - i + 1][n - j + 1] != a[i][j])
					a[i][j] = a[n - i + 1][n - j + 1], k--;
		if((k < 0) || (n % 2 == 0) && (k & 1)) cout << "NO\n";
		else cout << "YES\n";

	}
	return 0;
}