#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n;
	cin >> n;
	printf("%.9lf", n * (n + 1) / (2 * n - 1) / 2);
	return 0;
}