#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, base = 13331;
int n, cnt;
char c[N], s[N];
unsigned long long pc[N], ps[N];
inline void print(int x)
{
	cout << c[x]; cnt++;
	if(cnt == 80) cout << '\n', cnt -= 80;
}
int p[N] = {1};
inline int askc(int l, int r) {return pc[r] - pc[l - 1] * p[r - l + 1];}
inline int asks(int l, int r) {return ps[r] - ps[l - 1] * p[r - l + 1];}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> c[i], s[i] = c[i];
	reverse(s + 1, s + n + 1);
	for(int i = 1; i <= n; i++) pc[i] = pc[i - 1] * base + c[i];
	for(int i = 1; i <= n; i++) ps[i] = ps[i - 1] * base + s[i];
	for(int i = 1; i <= n; i++) p[i] = p[i - 1] * base;
	int L = 1, R = n;
	while(L < R)
	{
		if(c[L] < c[R]) {print(L++); continue;}
		if(c[L] > c[R]) {print(R--); continue;}
		if(c[L] == c[R])
		{
			if(askc(L, R) == asks(n - R + 1, n - L + 1)) {print(L++); continue;}
			int l = 1, r = R - L + 1;
			while(l <= r)
			{
				int mid = l + r >> 1;
				if(askc(L, L + mid - 1) == asks(n - R + 1, n - R + mid)) l = mid + 1;
				else r = mid - 1;
			}
			if(c[L + l - 1] < c[R - l + 1]) print(L++);
			else print(R--);
		}
	}
	cout << c[L];
	return 0;
}