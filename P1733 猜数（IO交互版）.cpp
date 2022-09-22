#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l = 1, r = 1000000000;
    while(l <= r)
    {
        int op;
        int mid = l + r >> 1;
        cout << mid << '\n';
        fflush(stdout);
        cin >> op;
        if(op == 0) break;
        else if(op == 1) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}