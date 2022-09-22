#include<bits/stdc++.h>
#define int long long
using namespace std;
int l, r, ans;
int sum(int x)
{
    if(x == 2) return 2;
    int cnt = x / 2 * 5;
    if(!(x & 1))  cnt -= 2;
    cnt += (x - 6) / 12 + 1;
    if(x < 6) cnt--;
    cnt += (x - 420) / 840 + 1;
    if(x < 420) cnt--;
    cnt += (x - 360360) / 720720 + 1;
    if(x < 360360) cnt--;
    cnt += (x - 72201776446800) / (72201776446800 << 1) + 1;
    if(x < 72201776446800) cnt--;
    return cnt - 1;
}
signed main()
{
    cin >> l >> r;
    // cout << sum(r) << '\n';
    cout << sum(r) - sum(l - 1);
    return 0;
}
/*
12个数为一个循环节
由第六位开始循环，和为31
7~18
19~30
求一个东西
*/