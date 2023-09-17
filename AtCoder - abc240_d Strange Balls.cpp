#include<bits/stdc++.h>
using namespace std;
int n, top;
int a[200005];
int stk[200005], cnt[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		stk[++top] = a[i];
		if(stk[top] == stk[top - 1]) cnt[top] = cnt[top - 1] + 1;
		else cnt[top] = 1;
		if(cnt[top] == a[i])
		{
			for(int j = 1; j <= a[i]; j++)
				top--;
		}
		cout << top << '\n';
	}
	return 0;
}