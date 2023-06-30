#include<bits/stdc++.h>
using namespace std;
int n, ans[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		for(int j = 2; j * j <= x; j++)
		{
			if(x % j != 0) continue;
			while(x % j == 0) x /= j;
			ans[j]++;
		}
		if(x > 1) ans[x]++;
	}
	int ANS = 1;
	for(int i = 1; i <= 100000; i++)
		ANS = max(ANS, ans[i]);
	cout << ANS;
	return 0;
}