#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[200005];
int main()
{
	cin >> T;
	while(T--)
	{
		int maxn = INT_MIN;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i], maxn = max(maxn, a[i]);
		if(maxn <= 0) {cout << maxn << '\n'; continue;}
		long long c1 = 0, c2 = 0;
		for(int i = 1; i <= n; i++)
		{
			if(i & 1) c1 = c1 + max(a[i], 0);
			else c2 = c2 + max(a[i], 0);
		}
		cout << max(c1, c2) << '\n';
	}
	return 0;
}