#include<bits/stdc++.h>
using namespace std;
int n, base = 13331;
inline int hs1(string x)
{
	unsigned long long p = 0;
	for(int i = 0; i < x.size(); i++)
		p = p * base + x[i];
	return p;
}
unsigned long long f[100005];
int main()
{
	int ans = 0;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		f[i] = hs1(s);
	}
	sort(f + 1, f + n + 1);
	for(int i = 1; i <= n; i++)
		if(f[i] != f[i - 1])
			ans++;
	cout << ans;
	return 0;
}