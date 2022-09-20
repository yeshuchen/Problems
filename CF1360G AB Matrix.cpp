#include<bits/stdc++.h>
using namespace std;
struct node{
    int now, id;
}a[1005];
int ans[105][105];
inline bool cmp(node x, node y)
{
    return x.now < y.now;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, m, A, B;
        cin >> n >> m >> A >> B;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                ans[i][j] = 0;
        for(int i = 1; i <= n; i++) a[i].now = 0, a[i].id = i;
        if(n * A != m * B)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 1; i <= m; i++)
        {
            sort(a + 1, a + n + 1, cmp);
            for(int j = 1; j <= B; j++)
                ans[a[j].id][i] = 1, a[j].now++;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                cout << ans[i][j];
            cout << '\n';
        }
    }
    return 0;
}