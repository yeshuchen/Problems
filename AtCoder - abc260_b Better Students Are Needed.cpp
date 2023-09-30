#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node {
	int id, math, english;
} a[N];
int n, x, y, z, tmp[N];
inline bool cmp1(node x, node y) {return x.math == y.math ? x.id < y.id : x.math > y.math;}
inline bool cmp2(node x, node y) {return x.english == y.english ? x.id < y.id : x.english > y.english;}
inline bool cmp3(node x, node y) {return x.math + x.english == y.math + y.english ? x.id < y.id : x.math + x.english > y.math + y.english;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> x >> y >> z;
	for(int i = 1; i <= n; i++)
		cin >> a[i].math, a[i].id = i;
	for(int i = 1; i <= n; i++)
		cin >> a[i].english;
	sort(a + 1, a + n + 1, cmp1);
	sort(a + x + 1, a + n + 1, cmp2);
	sort(a + x + y + 1, a + n + 1, cmp3);
	for(int i = 1; i <= x + y + z; i++) tmp[i] = a[i].id;
	sort(tmp + 1, tmp + x + y + z + 1);
	for(int i = 1; i <= x + y + z; i++) cout << tmp[i] << '\n';
	return 0;
}