#include<bits/stdc++.h>
using namespace std;
int T;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		double v1, v2, v3, a1, a2, t1, t2, s1, s2;
		cin >> v1 >> v2 >> v3 >> a1 >> a2;
		t1 = v1 / a1; t2 = v2 / a2;
		s1 = v1 * t1 + 0.5 * -a1 * t1 * t1;
		s2 = v2 * t2 + 0.5 * -a2 * t2 * t2;
		printf("Case %d: %.6lf %.6lf\n", i, s1 + s2, max(t1, t2) * v3);	
	}
	return 0;
}