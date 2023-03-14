#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[200005];
int main()
{
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 2, a + n + 1);
		for(int i = 2; i <= n; i++)
		{
			if(a[i] > a[1])
				a[1] += (a[i] - a[1] + 1) / 2;
		}
		cout << a[1] << '\n';
	}
	return 0;
}