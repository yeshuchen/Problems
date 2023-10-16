#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
struct node {
	int a, b;
} t[N];
int f[105][10005];
inline bool cmp(node x, node y) {return x.b > y.b;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; int res = 0, sum = 0;
	for(int i = 1; i <= n; i++) cin >> t[i].a, res += t[i].a;
	for(int i = 1; i <= n; i++) cin >> t[i].b;
	sort(t + 1, t + n + 1, cmp);
	for(int i = 1; i <= n; i++)
	{
		sum += t[i].b;
		if(sum >= res)
		{
			sum = 0;
			memset(f, -0x3f, sizeof(f));
			f[0][0] = 0;
			cout << i << ' ';
			for(int j = 1; j <= n; j++)
				for(int k = i; k; k--)
					for(int l = 10000; l >= t[j].b; l--)
						f[k][l] = max(f[k][l], f[k - 1][l - t[j].b] + t[j].a);
			for(int j = res; j <= 10000; j++)
				sum = max(sum, f[i][j]);
			cout << res - sum;
			return 0;
		}
	}
	return 0;
}