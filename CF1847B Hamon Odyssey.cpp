#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[500005], p[500005], s[500005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		s[n] = a[n];
		for(int i = n - 1; i; i--) s[i] = a[i] & s[i + 1];
		if(s[1] > 0) {cout << 1 << '\n'; continue;}
		int res = 0, cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			if(!res && !s[i]) res = a[i], cnt++;
			res &= a[i];
		}
		cout << cnt << '\n';
	}
	return 0;
}