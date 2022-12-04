#include<bits/stdc++.h>
using namespace std;
long long n, a, b, p, q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> a >> b >> p >> q;
	cout << n / a * p + n / b * q - (n / (a * b / __gcd(a, b)) * min(p, q)); 
	return 0;
}