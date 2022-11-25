#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int T, n;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int res = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i], res += (a[i] == 1);
		if(res != 1) {cout << "NO\n"; goto end;}
		for(int i = 1; i <= n; i++)
			if(a[i] < a[i % n + 1] && a[i % n + 1] - a[i] != 1)
			{
				cout << "NO\n";
				goto end;
			}
		cout << "YES\n";
		end:;
	}
	return 0;
}