#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
char s[N];
long long a[N];
long long T, n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int cnt = 0;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			cin >> s[i], cnt += (s[i] == '1');
		if(m * cnt % n)
		{
			cout << "-1\n";
			continue;
		}
		for(int i = 1; i <= n; i++)
		{
			if(s[i] == '1') a[i] = n - cnt;
			else a[i] = -cnt;
			a[i + n] = a[i];
		}
		for(int i = 1; i <= 2 * n; i++) a[i] += a[i - 1];
		int l = 0, r = 0;
		for(int i = m; i <= 2 * n; i++)
		{
			if(a[i] == a[i - m])
			{
				l = i - m + 1;
				r = i;
				break;
			}
		}
		if(r <= n) cout << "1\n" << l << ' ' << r << '\n';
		else cout << "2\n" << 1 << ' ' << r - n << '\n' << l << ' ' << n << '\n';
	}
	return 0;
}