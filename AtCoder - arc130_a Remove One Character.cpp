#include<bits/stdc++.h>
using namespace std;
int n;
char ch, last = '@';
int main()
{
	int cnt = 0;
	long long ans = 0;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> ch;
		if(ch == last) cnt++;
		if(ch != last || i == n)
			ans += 1ll * cnt * (cnt - 1) / 2, cnt = 1;
		last = ch;
	}
	cout << ans;
	return 0;
}