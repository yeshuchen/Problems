#include<bits/stdc++.h>
using namespace std;
int T, n, m;
char c[105][105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int cnt = 0;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> c[i][j];
		if(c[1][1] == '1') {cout << -1 << '\n'; continue;}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				if(c[i][j] == '1')
					cnt++;
		cout << cnt << '\n';
		for(int i = n; i >= 1; i--)
			for(int j = m; j > 1; j--)
				if(c[i][j] == '1')
					cout << i << ' ' << j - 1 << ' ' << i << ' ' << j << '\n';
		for(int i = n; i > 1; i--)
			if(c[i][1] == '1')
				cout << i - 1 << ' ' << 1 << ' ' << i << ' ' << 1 << '\n';
	}
	return 0;
}