#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, sz = 2000;
struct node {
	int x, y, id;
} a[N];
int in[N];
bool cmp(node x, node y) {return in[x.x] == in[y.x] ? x.y < y.y : in[x.x] < in[y.x];}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y, a[i].id = i, in[a[i].x] = a[i].x / sz + 1;
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++)
		cout << a[i].id << ' ';
	return 0;
}