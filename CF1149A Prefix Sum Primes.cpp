#include<bits/stdc++.h>
using namespace std;
int n, a[200005], d[10005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], d[a[i]]++;
	if(d[1] == 0)
	{
		for(int i = 1; i <= d[2]; i++)
			cout << 2 << ' ';
		return 0;
	}
	if(d[1] <= 2)
	{
		if(d[2]) cout << 2 << ' ';
		cout << 1 << ' ';
		for(int i = 2; i <= d[2]; i++) cout << 2 << ' ';
		if(d[1] > 1) cout << 1;
		return 0;
	}
	for(int i = 1; i <= 3; i++) cout << 1 << ' ';
	d[1] -= 3;
	for(int i = 1; i <= d[2]; i++) cout << 2 << ' ';
	for(int i = 1; i <= d[1]; i++) cout << 1 << ' ';
	return 0;
}