#include<bits/stdc++.h>
using namespace std;
int ans, r;
int f[30000005];
char s[30000005];
char t[30000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s + 1;
	t[1] = 'A';
	int len = strlen(s + 1), n = 1;
	for(int i = 1; i <= len; i++)
		t[++n] = '*', t[++n] = s[i];
	t[++n] = '*';
	t[++n] = 'K';
	int p = 1;
	for(int i = 1; i <= n; i++)
	{
		if(i < p + f[p]) f[i] = min(f[2 * p - i], p + f[p] - i);
		while(t[i + f[i]] == t[i - f[i]]) f[i]++;
		if(i + f[i] > p + f[p]) p = i;
		ans = max(ans, f[i] - 1);
	}
	cout << ans;
	return 0;
}