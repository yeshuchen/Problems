#include<bits/stdc++.h>
using namespace std;
int main()
{
	char c1, c2, c3;
	cin >> c1 >> c2 >> c3;
	if(c1 > c2) swap(c1, c2);
	if(c1 > c3) swap(c1, c3);
	if(c2 > c3) swap(c2, c3);
	if(c1 == c3) cout << -1;
	else if(c1 == c2) cout << c3;
	else cout << c1;
	return 0;
}