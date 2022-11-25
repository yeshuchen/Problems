#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, k;
int c[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	for(int i = 2; i * i <= k; i++)
	{
		if(k % i != 0) continue;
		int t = 1, flag = 0;
		while(k % i == 0)
			t *= i, k /= i;
		for(int j = 1; j <= n && !flag; j++)
			if(c[j] % t == 0)
				flag = 1;
		if(!flag) {cout << "No"; return 0;}
	}
	if(k)
	{
		bool flag = 0;
		for(int i = 1; i <= n && !flag; i++)
			if(c[i] % k == 0)
				cout << "Yes", flag = 1;
		if(!flag) cout << "No";
	}
	return 0;
}