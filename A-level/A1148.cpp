#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

const int maxn=101;
int p[maxn];
int q[maxn];
vector<int> ww,wi,poww,poi;
vector<pair<int,int> > ans;

int n;

void push(int a,int b){
	if(a>b){
		int temp=a;
		a=b;
		b=temp;
	}
	ans.push_back(make_pair(a,b));
}

void judge(int a,int b){
	fill(q,q+maxn,0);
	int cntw=0;
	int cnti=0;
	int pw=0;
	int pi=0;
	ww.clear();
	wi.clear();
	poi.clear();
	poww.clear();
	for(int i=1;i<=n;i++){
		int id=fabs(p[i]);
		int s=(p[i]>0?1:-1);
		if(id!=a&&id!=b){
			if(q[id]==0){
				q[id]=s;
				if(s==-1){
					cntw++;
					ww.push_back(id);
					if(cntw>1) return;
				}
			}
			else{
				if(s!=q[id]) return;
			}
		}
		else{
			if(q[id]==0){
				q[id]=s;
				if(s==-1){
					cnti++;
					wi.push_back(id);
					if(cnti>1) return;
				}
			}
			else{
				if(s!=q[id]) return;
			}
		}
	}
	if(q[a]==0){
		pi++;
		poi.push_back(a);
	}
	if(q[b]==0){
		pi++;
		poi.push_back(b);
	}
	if(pi==2) return;
	if(cntw+cnti>2) return;
	for(int i=1;i<=n;i++){
		if((i!=a&&i!=b)&&q[i]==0){
			pw++;
			poww.push_back(i);
		}
	}
	if(cntw+cnti==2){
		push(ww[0],wi[0]);
	}
	else if(cntw+cnti==0){
		for(int i=0;i<pw;i++){
			for(int j=0;j<pi;j++){
				push(poww[i],poi[j]);
			}
		}
	}
	else if(cntw==1){
		for(int i=0;i<pi;i++){
			push(ww[0],poi[i]);
		}
	}
	else{
		for(int i=0;i<pw;i++){
			push(wi[0],poww[i]);
		}
	}
	
}

bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.first!=b.first) return a.first<b.first;
	else return a.second<b.second;
}

int main(){
	scanf("%d",&n);
	fill(p,p+maxn,0);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			p[i]*=-1;
			p[j]*=-1;
			judge(i,j);
			p[i]*=-1;
			p[j]*=-1;
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	if(ans.size()==0) printf("No Solution");
	else{
		printf("%d %d\n",ans[0].first,ans[0].second);
	}
	return 0;
}
