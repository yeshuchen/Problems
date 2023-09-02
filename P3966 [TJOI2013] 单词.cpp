#include<bits/stdc++.h>
using namespace std;
char s[205][2000005];
int n, len[205], nxt[2000005];
inline void get_nxt(char *a, int l)
{
	nxt[1] = 0;
	for(int i = 2; i <= l; i++)
	{
		int j = nxt[i - 1];
		while(j && a[j + 1] != a[i]) j = nxt[j];
		if(a[j + 1] == a[i]) nxt[i] = j + 1;
		else nxt[j] = 0;
	}
}
inline int find(char *a, char *b, int lena, int lenb)
{
	int res = 0;
	for(int i = 1, j = 0; i <= lenb; i++)
	{
		while(j && b[i] != a[j + 1]) j = nxt[j];
		if(a[j + 1] == b[i]) j++;
		if(j == lena) res++;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i] + 1;
		len[i] = strlen(s[i] + 1);
	}
	// for(int i = 1; i <= n; i++) cout << len[i] << '\n';
	for(int i = 1; i <= n; i++)
	{
		int ans = 0; get_nxt(s[i], len[i]);
		for(int j = 1; j <= n; j++)
		{
			if(i == j) ans++;
			else if(len[i] <= len[j])
				ans += find(s[i], s[j], len[i], len[j]);
		}
		cout << ans << '\n';
	}
	return 0;
}