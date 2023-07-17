#include<bits/stdc++.h>
using namespace std;
int n, k, tot;
int p[100005];
char c[100005], tmp[100005];
inline bool check(int len)
{
	int cnt = 0;
	for(int i = 1; i <= tot; i++)
		cnt += p[i] / (len + 1);
	return cnt <= k;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	cin >> c + 1;
	int w = 0;
	for(int i = 1; i <= n; i++)
	{
		if((i & 1) && c[i] != 'N') w++;
		if(!(i & 1) && c[i] != 'F') w++;
	}
	if(w <= k || n - w <= k) {cout << 1; return 0;}
	p[++tot] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(c[i] == c[i - 1]) p[tot]++;
		else p[++tot] = 1;
	}
	int l = 2, r = n, ans;
	while(l <= r) 
	{
		int mid = l + r >> 1;
		if(check(mid)) r = (ans = mid) - 1;
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}