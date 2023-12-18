#include<bits/stdc++.h>
using namespace std;
const int N = 4e7 + 5;
long long ans;
char s[N], t[N];
int lcp[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s + 1 >> t + 1;
	int len = strlen(s + 1), n = strlen(t + 1);
	for(int i = 1; i <= len; i++)
		t[n + i] = s[i];
	n += len; t[n + 1] = '@'; lcp[1] = n;
	int pos = 0;
	for(int i = 2; i <= n; i++)
	{
		if(i > pos + lcp[pos] - 1)
		{
			lcp[i] = 1;
			while(t[i + lcp[i] - 1] == t[lcp[i]]) lcp[i]++;
			lcp[i]--; pos = i;
		}
		else
		{
			int l = pos, r = pos + lcp[pos] - 1;
			lcp[i] = max(min(lcp[i - l + 1], r - i + 1), 1);
			while(t[i + lcp[i] - 1] == t[lcp[i]]) lcp[i]++;
			lcp[i]--;
			if(i + lcp[i] - 1 > r) pos = i;
		}
	}
	for(int i = 1; i <= n - len; i++) ans ^= 1ll * i * (min(lcp[i], n - len - i + 1) + 1);
	cout << ans << '\n'; ans = 0;
	for(int i = n - len + 1; i <= n; i++) ans ^= 1ll * (i + len - n) * (min(lcp[i], n - len) + 1);
	cout << ans;
	return 0;
}