#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int n;
map<ull, ull> m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		ull x, sum = 0, w = 1;
		for(int j = 0; j < 6; j++)
		{
			cin >> x;
			sum += x;
			w *= x;
		}
		if(m[sum + w]) {cout << "Twin snowflakes found.\n"; return 0;}
		m[sum + w] = 1;
	}
	cout << "No two snowflakes are alike.";
	return 0;
}