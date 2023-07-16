#include<bits/stdc++.h>
using namespace std;
namespace in{
    #ifdef faster
    char buf[1<<21],*p1=buf,*p2=buf;
    inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
    #else
    inline int getc(){return getchar();}
    #endif
    template <typename T>inline void read(T& t){
        t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
        while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
    }
    template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace out{
    char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
    inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
    inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
    template <typename T>void write(T x) {
        static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
        while (len>=0)putc(buf[len]),--len;
    }
}
const int N = 2e5 + 5, inf = 1e9;
int tot = 1;
struct Edge {
	int nxt, y, z, w;
} e[N];
int n, m, S, T;
int head[N], dis[N], flow[N];
inline void addedge(int x, int y, int z, int w)
{
	e[++tot] = (Edge) {head[x], y, z, w};
	head[x] = tot;
}
inline void add(int x, int y, int z, int w)
{
	addedge(x, y, z, w);
	addedge(y, x, 0, -w);
}
int pre[N], vis[N];
inline bool spfa()
{
	queue<int> q;
	memset(dis, 0x3f, sizeof(int) * (n + 1));
	dis[S] = 0; flow[S] = inf; flow[T] = 0;
	q.push(S);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		vis[x] = 0;
		for(int i = head[x]; i; i = e[i].nxt)
		{
			int y = e[i].y, z = e[i].z, cost = e[i].w;
			if(!z || dis[y] <= dis[x] + cost) continue;
			dis[y] = dis[x] + cost;
			flow[y] = min(z, flow[x]);
			pre[y] = i;
			if(!vis[y]) q.push(y), vis[y] = 1;
		}
	}
	return flow[T];
}
int maxflow, mincost;
inline void update()
{	
	maxflow += flow[T];
	for(int x = T; x != S; x = e[pre[x] ^ 1].y)
	{
		e[pre[x]].z -= flow[T]; e[pre[x] ^ 1].z += flow[T];
		mincost += flow[T] * e[pre[x]].w;
	}
}
int main()
{
	in::read(n, m);
	S = 1; T = n;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z, w;
		in::read(x, y, z, w);
		add(x, y, z, w);
	}
	while(spfa())
		update();
	cout << maxflow << ' ' << mincost;
	return 0;
}