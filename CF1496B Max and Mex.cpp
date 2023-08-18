#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int T, n, k;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		if(!k) {cout << n << '\n'; continue;}
		sort(a + 1, a + n + 1);
		int mex = n;
		for(int i = 1; i <= n; i++)
			if(a[i] != i - 1)
			{
				mex = i - 1;
				break;
			}
		int p = (mex + a[n] + 1) / 2;
		if(mex <= a[n]) k = 0;
		else {cout << n + k << '\n'; continue;}
		if(a[lower_bound(a + 1, a + n + 1, p) - a] != p) n++;
		cout << n << '\n';
	}
	return 0;
}