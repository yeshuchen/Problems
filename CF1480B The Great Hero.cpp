#include<bits/stdc++.h>
using namespace std;
int T, A, B, n;
struct node{
	int a, b;
} t[1000005];
inline bool cmp(node x, node y) {return x.a < y.a;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		bool flag = 0;
		cin >> A >> B >> n;
		for(int i = 1; i <= n; i++) cin >> t[i].a;
		for(int i = 1; i <= n; i++) cin >> t[i].b;
		sort(t + 1, t + n + 1, cmp);
		for(int i = 1; i <= n; i++)
		{
			int cnth = (t[i].b - 1) / A + 1, cntm = (B - 1) / t[i].a + 1;
			B -= cnth * t[i].a;
			if(B <= 0 && i < n || cntm < cnth)
			{
				cout << "NO\n";
				flag = 1;
				break;
			}
		}
		if(!flag) cout << "YES\n";
	}
	return 0;
}