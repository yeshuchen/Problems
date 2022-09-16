#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e16, MAXN = 3e16;
int x0, y01, ax, ay, bx, by;
int xs, ys, t;
int tot, ans;
int x[1005], y[1005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> x0 >> y01 >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    x[1] = x0, y[1] = y01;
    for(int i = 2; i; i++)
    {
        x[i] = ax * x[i - 1] + bx;
        y[i] = ay * y[i - 1] + by;
        if((x[i] * ax + bx) <= x[i] || (y[i] * ay + by) <= y[i] || i >= 56)
        {
            tot = i - 1;
            break;
        }
    }
    for(int i = 1; i <= tot; i++)
        for(int j = i; j <= tot; j++)
        {
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) + min((abs(xs - x[i]) + abs(ys - y[i])), (abs(xs - x[j]) + abs(ys - y[j]))) <= t)
                ans = max(ans, j - i + 1);
        }
    cout << ans;
    return 0;
}