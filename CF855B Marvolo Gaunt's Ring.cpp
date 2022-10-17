#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, p, q, r;
ll a[100005];
priority_queue<ll> q1, q2, q3;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> p >> q >> r;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		q1.push(p * a[i]);
		ll x = q1.top();
		q2.push(x + q * a[i]);
		x = q2.top();
		q3.push(x + r * a[i]);
	}
	cout << q3.top();
	return 0;
}