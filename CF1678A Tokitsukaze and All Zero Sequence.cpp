#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int T, n;
int a[N], d[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 0; i <= 100; i++) d[i] = 0;
		for(int i = 1; i <= n; i++) cin >> a[i], d[a[i]]++;
		if(d[0]) {cout << n - d[0] << '\n'; continue;}
		for(int i = 1; i <= 100; i++)
			if(d[i] >= 2)
			{
				cout << n << '\n';
				goto here;
			}
		cout << n + 1 << '\n';
		here:;
	}
	return 0;
}