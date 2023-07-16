#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	int l = 1, r = n;
	while(l < r)
	{
		int x1, x2;
		int mid = l + r >> 1;
		cout << '?' << ' ' << mid << endl;
		fflush(stdout);
		cin >> x1;
		cout << '?' << ' ' << mid + 1 << endl;
		fflush(stdout);
		cin >> x2;
		if(x1 < x2) r = mid;
		else l = mid + 1;
	}
	cout << '!' << ' ' << l;
	fflush(stdout);
	return 0;
}