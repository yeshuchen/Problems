#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m, k;
int p[N], b[N], f[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 0; i <= m; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++)
	{
		for(int j = k; j >= 0; j--)
		{	
			for(int l = 0; l <= j; l++)
				f[j] = max(f[j - l] + b[p[i] + l], f[j]);
		}
	} 
    cout << f[k];
    return 0;
}
//dp[k]表示前i个球队取k张照片的最大值 