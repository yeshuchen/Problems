#include<bits/stdc++.h>
using namespace std;
int n, ans;
int p[5000005];
char s[5000005], str[5000005];
inline int Manacher()
{
	int maxn = 0, cnt = 1;
	int len = strlen(s + 1), mx = 0, id = -1;
	str[0] = '@'; str[1] = '#';
	for(int i = 1; i <= len; i++)
		str[++cnt] = s[i], str[++cnt] = '#';
	str[++cnt] = '&';
	for(int i = 1; i < cnt; i++)
	{
		if(i < mx) p[i] = min(p[2 * id - i], mx - i);
		else p[i] = 1;
		while(str[i + p[i]] == str[i - p[i]]) p[i]++;
		if(i + p[i] > mx)
			mx = i + p[i], id = i;
		maxn = max(maxn, p[i] - 1);
	}
	return maxn;
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s + 1;
		cout << Manacher() << '\n';
	}
}