#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, k;
int a[N];
long long r, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		r = 0;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		reverse(a + 1, a + n + 1);
		r = 2 * a[1] + 1;
		for(int i = 2; i <= n; i++)
		{
			if(r >= m) {cout << "NO\n"; goto end;}
			r += a[i] + 1;
		}
		cout << "YES\n";
		end:;
	}
	return 0;
}