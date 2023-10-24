#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n;
ll sum, a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	if(sum & 1) {cout << "NO"; return 0;}
	sum /= 2; ll res = 0; set<ll> s;
	for(int i = 1; i <= n; i++)
	{
		s.insert(a[i]); res += a[i];
		if(res == sum || res > sum && s.count(res - sum)) {cout << "YES"; return 0;}
	}
	s.clear();
	for(int i = n; i; i--)
	{
		s.insert(a[i]); res -= a[i];
		if(res < sum && s.count(sum - res)) {cout << "YES"; return 0;}
	}
	cout << "NO";
	return 0;
}