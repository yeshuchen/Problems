#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int T, n;
struct node{
    int op, val;
}a[N];
int w[4];
inline bool cmp(node x, node y)
{
    return x.val > y.val;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--)
    {
        int pos = 1;
        cin >> n;
        w[1] = w[0] = 0;
        for(int i = 1; i <= n; i++)
            cin >> a[i].op, w[a[i].op]++;
        for(int i = 1; i <= n; i++)
            cin >> a[i].val;
        sort(a + 1, a + n + 1, cmp);
        a[0].val = INT_MAX;
        int pos1 = 0, pos2 = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i].op && a[pos1].val > a[i].val) pos1 = i;
            else if(!a[i].op && a[pos2].val > a[i].val) pos2 = i;
        }
        int ans = 0;
        if(w[1] == w[0])
        {
            int pos;
            if(a[pos1].val > a[pos2].val) pos = pos2;
            else pos = pos1;
            for(int i = 1; i <= n; i++)
                ans += (i == pos ? 1 : 2) * a[i].val;
        }
        else if(w[1] > w[0])
        {
            int cnt = 0;
            for(int i = 1; i <= n; i++)
                if(!a[i].op) ans += 2 * a[i].val, cnt++;
            for(int i = 1; i <= n; i++)
            {
                if(!a[i].op) continue;
                if(i == pos1 || !cnt) ans += a[i].val;
                else ans += 2 * a[i].val, cnt--;
            }
        }
        else
        {
            int cnt = 0;
            for(int i = 1; i <= n; i++)
                if(a[i].op) ans += 2 * a[i].val, cnt++;
            for(int i = 1; i <= n; i++)
            {
                if(a[i].op) continue;
                if(i == pos2 || !cnt) ans += a[i].val;
                else ans += 2 * a[i].val, cnt--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}