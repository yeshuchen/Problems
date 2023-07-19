#include<bits/stdc++.h>
using namespace std;
int T, l, r;
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int cnt = 0;
		cin >> l >> r;
		int tmp = l, len, res = 0;
		while(tmp <= r)
		{
			cnt++;
			tmp <<= 1;
		}
		cout << cnt << ' '; len = (1 << cnt - 1);
		tmp /= 2; res += (r - tmp) / len + 1;
		if(len > 1) len = len / 2 * 3;
		if(l * len <= r)
		{
			tmp = l * len;
			res += ((r - tmp) / len + 1) * (cnt - 1);
		}
		cout << res << '\n';
	}
	return 0;
}