#include<bits/stdc++.h>
using namespace std;
int T, n, a;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		long long sum = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a, sum += a;
		if(sum < 0) sum = -sum;
		cout << sum << '\n';
	}
	return 0;
}