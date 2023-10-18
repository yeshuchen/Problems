#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, ans = LLONG_MAX;
int pr[20] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
void dfs(int num, int cnt, int last, int pos)
{
	if(num > n || cnt > ans) return;
	if(num == n) {ans = cnt; return;}
	int base = 1;
	for(int i = 1; i <= last; i++)
	{
		base *= pr[pos];
		if(LLONG_MAX / base < cnt) break;
		dfs(num * (i + 1), cnt * base, i, pos + 1);
	}	
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	dfs(1, 1, 60, 1);
	cout << ans;
	return 0;
}