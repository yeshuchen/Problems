#include<bits/stdc++.h>
using namespace std;
int T, n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		if(n < m)
		{
			cout << n + 1 << '\n';
			for(int i = 1; i <= n; i++, cout << '\n')
				for(int j = 0; j < m; j++)
					cout << (i + j - 1) % m << ' ';
		}
		if(n >= m)
		{
			if(m == 1)
			{
				cout << 0 << '\n';
				for(int i = 1; i <= n; i++) cout << 0 << '\n';
			}
			else
			{
				cout << m << '\n';
				for(int i = 1; i < m; i++, cout << '\n')
					for(int j = 0; j < m; j++)
						cout << (i + j - 1) % m << ' ';
				for(int i = m; i <= n; i++, cout << '\n')
					for(int j = 0; j < m; j++)
						cout << j << ' ';
			}
		}
	}
	return 0;
}