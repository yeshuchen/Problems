#include<bits/stdc++.h>
using namespace std;
struct node{
	int val, id;
} a[200005];
int T, n;
bool v1[200005], v2[200005];
int a1[200005], a2[200005];
inline bool cmp(node x, node y) {return x.val < y.val;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i].val, a[i].id = i;
		sort(a + 1, a + n + 1, cmp);
		int p1 = 1, p2 = 1;
		for(int i = 1; i <= n; i++)
		{
			if(!v1[a[i].val]) v1[a[i].val] = 1, a1[a[i].id] = a[i].val, a2[a[i].id] = p2++;
			else if(!v2[a[i].val]) v2[a[i].val] = 1, a1[a[i].id] = p1++, a2[a[i].id] = a[i].val;
			else {cout << "NO\n"; goto end;}
			if(a[i].val < p1 && a[i].val < p2) {cout << "NO\n"; goto end;}
			while(v1[p1]) p1++;
			while(v2[p2]) p2++;
		}
		cout << "YES\n";
		for(int i = 1; i <= n; i++)
			cout << a1[i] << ' ';
		cout << '\n';
		for(int i = 1; i <= n; i++)
			cout << a2[i] << ' ';
		cout << '\n';
		end:;
		for(int i = 1; i <= n; i++)
			v1[i] = v2[i] = 0;
	}
	return 0;
 } 
