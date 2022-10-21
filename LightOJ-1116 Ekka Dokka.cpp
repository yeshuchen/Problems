#include<bits/stdc++.h>
using namespace std;
int T, cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		long long n;
		cout << "Case " << ++cnt << ": ";
		cin >> n;
		if(n & 1) cout << "Impossible";
		else
		{
			long long base = 1;
			while(n % 2 == 0) n /= 2, base *= 2;
			cout << n << ' ' << base;
		}
		cout << '\n';
	}
	return 0;
} 