#include<bits/stdc++.h>
using namespace std;
int T, n, m;
int R[505], C[505];
char c[505][505], d[505][505];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> m; bool f = 0;
		for(int i = 1; i <= max(n, m); i++) R[i] = C[i] = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
			{
				cin >> c[i][j];
				if(c[i][j] != '.')
					R[i]++, C[j]++;
			}
		for(int i = 1; i <= n; i++)
			if(R[i] & 1) f = 1;
		for(int i = 1; i <= m; i++)
			if(C[i] & 1) f = 1;
		if(f) {cout << -1 << '\n'; continue;}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
			{
				if(c[i][j] == '.') {d[i][j] = c[i][j]; continue;}
				if(i + j & 1) d[i][j] = 'W';
				else d[i][j] = 'B';
			}
		for(int i = 1; i <= m; i++)
		{
			int cnt1 = 0, cnt2 = 0;
			for(int j = 1; j <= n; j++)
			{
				if(d[j][i] == 'W') cnt1++;
				if(d[j][i] == 'B') cnt2++;
			}
			int tmp = cnt1 - cnt2;
			for(int j = 1; j <= n; j++)
			{
				if(c[j][i] != 'L') continue;
				if(tmp > 0 && d[j][i] == 'W') d[j][i] = 'B', d[j][i + 1] = 'W', tmp -= 2;
				if(tmp < 0 && d[j][i] == 'B') d[j][i] = 'W', d[j][i + 1] = 'B', tmp += 2;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			int cnt1 = 0, cnt2 = 0;
			for(int j = 1; j <= m; j++)
			{
				if(d[i][j] == 'W') cnt1++;
				if(d[i][j] == 'B') cnt2++;
			}
			int tmp = cnt1 - cnt2;
			for(int j = 1; j <= m; j++)
			{
				if(c[i][j] != 'U') continue;
				if(tmp > 0 && d[i][j] == 'W') d[i][j] = 'B', d[i + 1][j] = 'W', tmp -= 2;
				if(tmp < 0 && d[i][j] == 'B') d[i][j] = 'W', d[i + 1][j] = 'B', tmp += 2;
			}
		}
		for(int i = 1; i <= n; i++, cout << '\n')
			for(int j = 1; j <= m; j++)
				cout << d[i][j];
	}
	return 0;
}