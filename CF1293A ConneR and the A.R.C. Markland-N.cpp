#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        map<int,int> f;
        int n, s, k;
        cin >> n >> s >> k;
        int l = s, r = s;
        for(int i = 1; i <= k; i++)
        {
            int w;
            cin >> w;
            f[w] = 1;
        }
        while(f[l] && l < n) l++;
        while(f[r] && r > 1) r--;
        if(f[r]) cout << l - s << '\n';
        else if(f[l]) cout << s - r << '\n';
        else cout << min(l - s, s - r) << '\n';
    }
    return 0;
}