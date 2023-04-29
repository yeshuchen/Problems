#include<bits/stdc++.h>
using namespace std;
int n, x, y;
inline int exgcd(int a, int b)
{
	if(a % b == 0) {x = 0, y = 1; return b;}
	int gcd = exgcd(b, a % b);
	int t = x;
	x = y; y = t - a / b * y;
	return gcd;
}
int main()
{
	int a, b;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> a >> b;
	int gcd = exgcd(a, b);
	int mod = b / gcd; 
	cout << (x % mod + mod) % mod;
	return 0;
}