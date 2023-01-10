#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int T, n, a[N];
int main()
{
	cin >> T;
	while(T--)
	{
		int c1 = 0, c2 = 0;
		int minn = INT_MAX, maxn = INT_MIN;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
			maxn = max(maxn, a[i]), minn = min(minn, a[i]);
		if(maxn == minn) {cout << 1ll * n * (n - 1) << '\n'; continue;}
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == maxn) c1++;
			if(a[i] == minn) c2++;
		}
		cout << 1ll * c1 * c2 * 2 << '\n';
	}
	return 0;
}