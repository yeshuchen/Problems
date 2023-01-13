#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct node{
	double x, y;
}a[N];
int n;
int top, stk[N];
inline bool cmp(node x, node y) {return (x.x == y.x ? x.y < y.y : x.x < y.x);}
inline double cross(node a, node b) {return a.x * b.y - a.y * b.x;}
inline double xcross(node a, node b, node c)
{
	node A = node{b.x - a.x, b.y - a.y};
	node B = node{c.x - a.x, c.y - a.y};
	return (cross(A, B) <= 0);
}
inline double dist(int i, int j) {return sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));}
double ans;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y;
	sort(a + 1, a + n + 1, cmp);
	stk[++top] = 1; stk[++top] = 2;
	for(int i = 3; i <= n; i++)
	{
		while(top > 1 && xcross(a[stk[top - 1]], a[stk[top]], a[i])) top--;
		stk[++top] = i;
	}
	for(int i = 2; i <= top; i++)
		ans += dist(stk[i - 1], stk[i]);
	top = 0;
	stk[++top] = n; stk[++top] = n - 1;
	for(int i = n - 2; i; i--)
	{
		while(top > 1 && xcross(a[stk[top - 1]], a[stk[top]], a[i])) top--;
		stk[++top] = i;
	}
	for(int i = 2; i <= top; i++)
		ans += dist(stk[i - 1], stk[i]);
	printf("%.2lf", ans);
	return 0;
}