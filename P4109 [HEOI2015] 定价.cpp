#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
inline int check(int val)
{
	int cnt = 0, flag = 0;
	if(val % 10 == 5) flag = 1;
	while(val) val /= 10, cnt++;
	return 2 * cnt - flag;
}
int minn = INT_MAX, ans;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--) {
		minn = INT_MAX, ans = -1;
		int l, r, base = 1;	
		cin >> l >> r;
		while(l <= r)
		{
			int x = l, cnt = 1;
			while(x % 10 == 0) x /= 10, cnt *= 10;
			int p = check(x);
			if(p < minn) minn = p, ans = l;
			l += cnt;
		}
		cout << ans << '\n';
	}
	return 0;
}