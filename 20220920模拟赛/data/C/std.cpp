#include<cstdio>
int n,f[1001],l[1001],d,ans;
int main(){
	scanf("%d",&n);
 for(register int i=1;i<=n;i++)scanf("%d",l+i);
 for(register int i=1;i<=n;i++){
	 scanf("%d",&d);
 for(register int j=n;j>=l[i];j--){
 if(f[j]<f[j-l[i]]+d){
 f[j]=f[j-l[i]]+d;if(ans<f[j])ans=f[j];
}
 }
 }
 printf("%d",ans);
}
