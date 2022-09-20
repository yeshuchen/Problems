#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
const int N=1e5+5,M=1e6+5;
ll sum,m;
int n,now,ans;
struct rest{
ll x;
int time;
}p[N];
priority_queue<int>q;
inline int read()
{
int s=0,fl=1;
char c=getchar();
while(c>'9'||c<'0')
{
if(c=='-')fl=-1;
c=getchar();
}
while(c<='9'&&c>='0')s=(s<<1)+(s<<3)+(c^48),c=getchar();
return s*fl;
}
inline ll lread()
{
ll s=0,fl=1;
char c=getchar();
while(c>'9'||c<'0')
{
if(c=='-')fl=-1;
c=getchar();
}
while(c<='9'&&c>='0')s=(s<<1)+(s<<3)+(c^48),c=getchar();
return s*fl;
}
inline bool cmp(rest a,rest b)
{
return a.x<b.x;
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
n=read();
m=lread();
for(int i=1;i<=n;i++)p[i].x=lread(),p[i].time=read();
sort(p+1,p+1+n,cmp);
for(int i=1;i<=n;i++)
{
m-=p[i].x-p[i-1].x;
if(m<=0)break;
q.push(p[i].time);
sum+=1ll*p[i].time;
now++;
while(sum>m)
{
sum-=1ll*q.top();
q.pop();
now--;
}
if(ans<now)ans=now;
}
printf("%d",ans);
return 0;
}
/*
2 10
1 100
5 5
*/
