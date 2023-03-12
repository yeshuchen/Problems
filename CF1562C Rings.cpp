#include<bits/stdc++.h>
using namespace std;
int n, T;
char c[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> c[i];
		int flag = 0;
		for(int i = 1; i <= n; i++)
			if(c[i] == '0')
			{
				if(i <= n / 2) cout << i << ' ' << n << ' ' << i + 1 << ' ' << n << '\n';
				else cout << 1 << ' ' << i << ' ' << 1 << ' ' << i - 1 << '\n';
				flag = 1;
				break;
			}
		if(!flag) cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << '\n';
	}
	return 0;
}