#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N = 2e6 + 5;
int n, w, sa[N], rk[N], old[N];
char s[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s + 1;
	n = strlen(s + 1);
	for(int i = 1; i <= n; i++) sa[i] = i, rk[i] = s[i];
	for(w = 1; w < n; w <<= 1)
	{
		stable_sort(sa + 1, sa + n + 1, [](int x, int y) {
			return rk[x] == rk[y] ? rk[x + w] < rk[y + w] : rk[x] < rk[y];
		});
		for(int i = 1; i <= n; i++) old[i] = rk[i];
		for(int i = 1, p = 0; i <= n; i++)
		{
			if(old[sa[i]] == old[sa[i - 1]] && old[sa[i] + w] == old[sa[i - 1] + w]) rk[sa[i]] = p;
			else rk[sa[i]] = ++p;
		}
	}
	for(int i = 1; i <= n; i++) cout << sa[i] << ' ';
	return 0;
}