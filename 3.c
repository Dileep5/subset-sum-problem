#include<stdio.h>
int edge[102][102],s,d,p,n,m,ans,path[102],finp[102],l,lp;
char v[102];
 
void dfs(int x,int p){
	int i;
	path[l++]=x;
	if(x==d){
		if(p>ans){
			ans=p;
			for(i=0;i<l;i++)
				finp[i]=path[i];
			lp=l;
		}
		l--;
		return;
	}
	v[x]=1;
	for(i=1;i<=n;i++){
		if(edge[x][i]>0 && v[i]==0){
			v[i]=1;
			if(edge[x][i]<p)
				dfs(i,edge[x][i]);
			else
				dfs(i,p);
			v[i]=0;
		}
	}
	v[x]=0;
	l--;
}
 
int main(){
	int i,j;
	scanf("%d %d",&n,&m);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			edge[i][j]=-1;
		v[i]=0;
	}
	for(i=1;i<=m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		edge[x][y]=edge[y][x]=z-1;
	}
	scanf("%d %d %d",&s,&d,&p);
	ans=-1;
	l=0;
	dfs(s,1000000000);
	for(i=0;i<lp;i++)
		printf("%d ",finp[i]);
	printf("\n%d\n",(p-1)/ans+1);
	return 0;
}
