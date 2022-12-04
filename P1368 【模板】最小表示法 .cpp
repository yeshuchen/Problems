#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = n + 1; i <= 2 * n; i++)
		a[i] = a[i - n];
	int i = 1, j = 2;
	while(i <= n && j <= n)
	{
		int k = 0;
		while(a[i + k] == a[j + k]) k++;
		if(a[i + k] > a[j + k])
		{
			i = i + k + 1;
			if(i == j) i = j + 1;
		}
		else
		{
			j = j + k + 1;
			if(i == j) i = j + 1;
		}
	}
	if(j > n)
	{
		for(int p = i; p <= i + n - 1; p++)
			cout << a[p] << ' ';
	}
	else
	{
		for(int p = j; p <= j + n - 1; p++)
			cout << a[p] << ' ';
	}
	return 0;
}