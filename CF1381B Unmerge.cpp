#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[5005];
bool f[5005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		memset(f, 0, sizeof(int) * (n + 1));
		f[0] = 1;
		for(int i = 1; i <= 2 * n; i++)
			cin >> a[i];
		a[2 * n + 1] = INT_MAX;
		int pos = 1;
		for(int i = 2; i <= 2 * n + 1; i++)
			if(a[i] > a[pos])
			{
				for(int j = n; j >= i - pos; j--)
					f[j] |= f[j - (i - pos)];
				pos = i;
			}
		if(f[n]) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}