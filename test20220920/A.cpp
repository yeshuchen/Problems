#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, cnt;
int a[500006];
int pf[20], px[20], py[20];
signed main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int wf = 0; wf < 360; wf += 90)
    {
        int x = 0, y = 0, f = wf;
        for(int i = 1; i <= n; i++)
        {
            if(f == 0) x += a[i];
            if(f == 90) y -= a[i];
            if(f == 180) x -= a[i];
            if(f == 270) y += a[i];
            f = (f + a[i] * 90) % 360;
        }
        pf[++cnt] = f / 90 + 1, px[cnt] = x, py[cnt] = y;
    }
    int f = 0, X = 0, Y = 0;
    for(int i = 1; i <= m; i++)
    {
        X += px[f / 90 + 1], Y += py[f / 90 + 1];
        f = pf[f / 90 + 1] * 90 - 90;
    }
    cout << abs(X) + abs(Y);
    return 0;
}
