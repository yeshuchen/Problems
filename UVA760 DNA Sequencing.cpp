#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, m, w, len;
string p[N];
char s[N], t[N], S[N];
int sa[N], rk[N], oldrk[N], height[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(cin >> s + 1)
	{
		cin >> t + 1;
		n = strlen(s + 1);
		m = strlen(t + 1);
		len = n + m + 1;
		memset(sa, 0, sizeof(sa));
		memset(rk, 0, sizeof(rk));
		memset(oldrk, 0, sizeof(oldrk));
		memset(height, 0, sizeof(height));
		for(int i = 1; i <= n; i++)
			S[i] = s[i];
		S[n + 1] = '@';
		for(int i = n + 2; i <= len; i++)
			S[i] = t[i - n - 1];
		for(int i = 1; i <= len; i++) s[i] = S[i];
		for(int i = 1; i <= len; i++) sa[i] = i, rk[i] = s[i];
		for(w = 1; w < len; w <<= 1)
		{
			sort(sa + 1, sa + len + 1, [](int a, int b) {
				return rk[a] == rk[b] ? rk[a + w] < rk[b + w] : rk[a] < rk[b];
			});
			memcpy(oldrk + 1, rk + 1, len * sizeof(int));
			for(int i = 1, p = 0; i <= len; i++)
			{
				if(oldrk[sa[i]] == oldrk[sa[i - 1]] && oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) rk[sa[i]] = p;
				else rk[sa[i]] = ++p;
			}
		}
		int k = 0;
		for(int i = 1; i <= len; i++)
		{
			if(k) k--;
			int j = sa[rk[i] - 1];
			while(i + k <= len && j + k <= len && s[i + k] == s[j + k]) k++;
			height[rk[i]] = k;
		}
		// for(int i = 1; i <= len; i++) cout << s[i];
		// cout << '\n';
		// for(int i = 1; i <= len; i++) cout << sa[i] << ' ';
		// cout << '\n';
		// for(int i = 1; i <= len; i++) cout << height[i] << ' ';
		// cout << '\n';
		int mx = 0;
		for(int i = 2; i <= len; i++)
			if(sa[i] <= n && sa[i - 1] > n + 1 || sa[i] > n + 1 && sa[i - 1] <= n)
				mx = max(mx, height[i]);
		int cnt = 0;
		if(!mx) {cout << "No common sequence.\n\n"; continue;}
		for(int i = 2; i <= len; i++)
		{
			if(sa[i] <= n && sa[i - 1] <= n || sa[i] > n + 1 && sa[i - 1] > n + 1) continue;
			if(height[i] == mx)
			{
				p[++cnt] = "";
				for(int j = sa[i]; j <= sa[i] + mx - 1; j++)
					p[cnt] += s[j];
			}
		}
		sort(p + 1, p + cnt + 1);
		cnt = unique(p + 1, p + cnt + 1) - p - 1;
		for(int i = 1; i <= cnt; i++) cout << p[i] << '\n';
		cout << '\n';
	}
	cout << '\n';
	return 0;
}