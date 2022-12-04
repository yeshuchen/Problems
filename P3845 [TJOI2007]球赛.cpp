#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int T, n;
struct node{
    int x, y;
}a[N];
int c[N], f[N];
inline bool cmp(node x, node y) {return (x.x == y.x ? x.y > y.y : x.x > y.x);}
int main()
{
    cin >> T;
    while(T--)
    {
		memset(f, 0, sizeof(f));
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
			scanf("%d-%d", &a[i].x, &a[i].y);
            if(a[i].x > a[i].y) swap(a[i].x, a[i].y);
        }
        sort(a + 1, a + n + 1, cmp);
        for(int i = 1; i <= n; i++)
            c[i] = a[i].y;
		f[1] = c[1];
		int tot = 1;
        for(int i = 2; i <= n; i++)
		{
			if(c[i] > f[tot]) f[++tot] = c[i];
			else f[lower_bound(f + 1, f + tot + 1, c[i]) - f] = c[i];
		} 
        cout << tot << '\n';
    }
    return 0;
}