#include<bits/stdc++.h>
using namespace std;
int T, n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		double ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) 
			ans += 1.0 * n / i;
		printf("%.2lf\n", ans);
	}
	return 0;
}