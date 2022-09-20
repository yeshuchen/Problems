#include <bits/stdc++.h>
#define ll long long
#define getchar nc
using namespace std;
inline char nc(){
 static char buf[100000],*p1=buf,*p2=buf;
 return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
 register int x=0,f=1;register char ch=getchar();
 while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
 while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
 return x*f;
}
inline void write(register ll x)
{
 if(!x)putchar('0');if(x<0)x=-x,putchar('-');
 static int sta[20];register int tot=0;
 while(x)sta[tot++]=x%10,x/=10;
 while(tot)putchar(sta[--tot]+48);
}
int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
int n,T,tot,ak;
ll ax,ay;
int main()
{
 n=read(),T=read();
 ll px=0,py=0;
 int k=0;
 while(n--)
 {
 int a=read();
 tot+=a;
 px+=1ll*dx[k]*a;
 py+=1ll*dy[k]*a;
 k=(k+a)%4;
 // printf("%lld %lld %d %d\n",px,py,a,k);
 }
 // printf("%d\n",k);
 // printf("%d %lld %lld %d\n",k,px,py,k);
 for(register int i=1;i<=T;++i)
 {
 if(ak==0)
 ax+=px,ay+=py;
 else if(ak==1)
 ax+=py,ay+=-px;
 else if(ak==2)
 ax+=-px,ay+=-py;
 else
 ax+=-py,ay+=px;
 // printf("%lld %lld\n",ax,ay);
 ak=(ak+k)%4;
 }
 write(fabs(ax)+fabs(ay));
return 0;
}
