#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
char c[1000005];
int nxt[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> c[i];
	nxt[1] = 0;
	for(int i = 2; i <= n; i++)
	{
		int p = nxt[i - 1];
		while(p && c[p + 1] != c[i]) p = nxt[p];
		if(c[p + 1] == c[i]) nxt[i] = p + 1;
		else nxt[i] = 0;
	}
	for(int i = 1; i <= n; i++)
	{
		int p = i;
		while(nxt[p]) p = nxt[p];
		nxt[i] = p;
		ans += i - p;
	}
	cout << ans;
	return 0;
}