#include<cstdio>
#include<vector>
#include<algorithm>
#include<map> 
using namespace std;

int n,m,k,temp,v1,v2;
const int maxn=10010;
map<int,int> mp;

vector<int> node[maxn];

bool inq[maxn];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&v1,&v2);
		node[v1].push_back(v1*10000+v2);
		node[v2].push_back(v2*10000+v1);
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&temp);
		mp.clear();
		int cnt=0;
		for(int j=0;j<temp;j++){
			scanf("%d",&v1);
			for(int p=0;p<node[v1].size();p++){
				if(mp.find(node[v1][p])==mp.end()){
					cnt++;
					int arc=node[v1][p];
					int ar=arc%10000;
					ar*=10000;
					ar+=arc/10000;
					mp[arc]++;
					mp[ar]++;
				}
			}
		}
		if(cnt==m) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
