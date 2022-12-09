#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		long long n, ans, sum = 0;
		cin >> n;
		ans = 4 * n * n;
		if(n % 2 == 0)
		{
			sum += 2 * n * (n / 2);
			sum = (ans - sum) / n;
			for(int i = 0; i <= n / 2 - 1; i++)
				cout << sum + i << ' ' << sum + 2 * n - i << ' ';
			cout << '\n';
		}
		else
		{
			sum = 3 * n;			
			sum += 2 * n * (n / 2 - 1);
			sum = (ans - sum) / n;
			for(int i = 0; i <= n / 2 - 1; i++)
				cout << sum + i << ' ' << sum + 2 * n - i << ' ';
			cout << sum + n << '\n';
		}
	}
	return 0;
}