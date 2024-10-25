#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int inf=1<<30;
const int maxn=220;
int arc[maxn][maxn];
int n,m,k,q,a,b,temp;
vector<int> ve;
bool inq[maxn];

int main(){
	scanf("%d%d",&n,&m);
	fill(arc[0],arc[0]+maxn*maxn,inf);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		arc[a][b]=arc[b][a]=1;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		bool flag=true;
		ve.clear();
		fill(inq,inq+maxn,false);
		scanf("%d",&temp);
		if(temp!=n+1) flag=false;
		ve.resize(temp);
		for(int j=0;j<temp;j++){
			scanf("%d",&ve[j]);
			if((inq[ve[j]]==true&&j!=temp-1)||(j==temp-1&&ve[0]!=ve[j])){
				flag=false;
			}
			else{
				inq[ve[j]]=true;
			}
		}
		if(flag==true){
			for(int u=0;u<temp-1;u++){
				if(arc[ve[u]][ve[u+1]]==inf){
					flag=false;
					break;
				}
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
