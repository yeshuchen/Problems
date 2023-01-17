#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, k;
int qmax[N], qmin[N];
int tailmx, tailmn, headmx = 1, headmn = 1;
struct node{
	int x, y;
}a[N];
int ans = INT_MAX;
inline bool cmp(node x, node y) {return x.x < y.x;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y;
	sort(a + 1, a + n + 1, cmp);
	for(int l = 1, r = 0; l <= n; l++)
	{
		while(qmax[headmx] < l && headmx <= tailmx) headmx++;
		while(qmin[headmn] < l && headmn <= tailmn) headmn++;
		while(a[qmax[headmx]].y - a[qmin[headmn]].y < k && r < n)
		{
			r++;
			while(tailmx >= headmx && a[qmax[tailmx]].y <= a[r].y) tailmx--;
			while(tailmn >= headmn && a[qmin[tailmn]].y >= a[r].y) tailmn--;
			qmax[++tailmx] = r;
			qmin[++tailmn] = r;
		}
		if(a[qmax[headmx]].y - a[qmin[headmn]].y >= k) ans = min(ans, a[r].x - a[l].x);
	}
	if(ans == INT_MAX) ans = -1;
	cout << ans;
	return 0;
}