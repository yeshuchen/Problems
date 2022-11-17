#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int cnt = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i], cnt += (a[i] < 0);
		for(int i = 1; i <= cnt; i++)
			if(a[i] > 0) a[i] *= -1;
		for(int i = cnt + 1; i <= n; i++)
			if(a[i] < 0) a[i] *= -1;
		for(int i = 2; i <= n; i++)
			if(a[i] < a[i - 1])
			{
				cout << "NO\n";
				goto end;
			}
		cout << "YES\n";
		end:;
	}
	return 0;
}