#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 4;
int n;
int l[N], pos[N];
int a[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        pos[i] = 1;
        cin >> l[i], cnt += l[i];
        a[i][l[i] + 1] = INT_MAX; 
        for(int j = 1; j <= l[i]; j++)
            cin >> a[i][j];
    }
    while(cnt)
    {
        cnt--;
        int p = 1;
        for(int i = 1; i <= n; i++)
        {
            if(a[i][pos[i]] < a[p][pos[p]])
                p = i;
            if(a[i][pos[i]] == a[p][pos[p]])
            {
                int x = pos[i], y = pos[p];
                while(a[i][x] == a[p][y] && x <= l[i] && y <= l[p])
                    x++, y++;
                if(a[i][x] < a[p][y])
                    p = i;
            }
        }
        cout << a[p][pos[p]++] << ' ';
    }
    return 0;
}