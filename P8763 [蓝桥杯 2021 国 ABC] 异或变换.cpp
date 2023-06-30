#include<bits/stdc++.h>
using namespace std;
int n, x = 1;
long long t;
char c[100005];
int a[2][100005];
int main()
{
	cin >> n >> t;
	while(x <= n) x <<= 1;
	t %= x;
	for(int i = 1; i <= n; i++)
		cin >> c[i], a[0][i] = c[i] - '0';
	for(int i = 1; i <= t; i++)
	{
		for(int j = 2; j <= n; j++)
			a[1][j] = a[0][j] ^ a[0][j - 1];
		for(int j = 2; j <= n; j++)
			a[0][j] = a[1][j]; 
	}
	for(int i = 1; i <= n; i++)
		cout << a[0][i];
	return 0;
}