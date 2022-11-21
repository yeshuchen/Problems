#include<bits/stdc++.h>
using namespace std;
int n;
inline bool check(int x)
{
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0) return false;
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	if(check(n)) {cout << 1; return 0;}
	if(check(n - 2)) {cout << 2; return 0;}
	if(n & 1) cout << 3;
	else cout << 2;
	return 0;
}