#include<bits/stdc++.h>
using namespace std;
int T, a[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
		{
			for(int j = 2; j <= i + 1; j++)
				if(a[i] % j != 0)
					goto here;
			cout << "NO\n";
			goto end;
			here:;
		}
		cout << "YES\n";
		end:;
	}
	return 0;
}