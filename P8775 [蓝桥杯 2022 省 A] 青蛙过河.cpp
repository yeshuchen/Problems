#include<bits/stdc++.h>
using namespace std;
int n, x;
int s[100005];
inline bool check(int w)
{
	for(int i = w; i < n; i++)
		if(s[i] - s[i - w] < x)
			return false;
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> x; x <<= 1;
	for(int i = 1; i < n; i++)
		cin >> s[i], s[i] += s[i - 1];
	int l = 1, r = n;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l;
	return 0;
}