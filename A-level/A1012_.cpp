#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

struct node{
	int id;
	int a;
	double clas[4];
	int rank[4];
}Node[1000000];
int n,m,name;
double cc,mm,ee,aa;
vector<node> ans;
set<int> st;


map<int,int> mp;


bool cmp0(node a,node b){
	if(a.clas[0]!=b.clas[0]) return a.clas[0]>b.clas[0];
	else return a.id<b.id;
}
bool cmp1(node a,node b){
	if(a.clas[1]!=b.clas[1]) return a.clas[1]>b.clas[1];
	else return a.id<b.id;
}
bool cmp2(node a,node b){
	if(a.clas[2]!=b.clas[2]) return a.clas[2]>b.clas[2];
	else return a.id<b.id;
}
bool cmp3(node a,node b){
	if(a.clas[3]!=b.clas[3]) return a.clas[3]>b.clas[3];
	else return a.id<b.id;
}

void getans(int j){
	int cnt=1;
	ans[0].rank[j]=1;
	if(j==3){
		mp[ans[0].id]=0;
	}
	for(int i=1;i<ans.size();i++){
		if(ans[i].clas[j]==ans[i-1].clas[j]){
			ans[i].rank[j]=ans[i-1].rank[j];
			cnt++;
		}
		else{
			ans[i].rank[j]=cnt++;
		}
		if(j==3){
			ans[i].a=0;
			int k=1;
			while(k<=3){
				if(ans[i].rank[ans[i].a]<ans[i].rank[k]){
					ans[i].a=k;
				}
			}
			mp[ans[i].id]=i;
		}
	}
	
}
char cla[4]={'A','C','M','E'};

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%lf%lf%lf",&name,&cc,&mm,&ee);
		Node[name].id=name;
		Node[name].a=4;
		Node[name].clas[1]=cc;
		Node[name].clas[2]=mm;
		Node[name].clas[3]=ee;
		Node[name].clas[0]=(cc+mm+ee)/3;
		st.insert(name);
		mp[name]=i;
		ans.push_back(Node[name]);
	}
	sort(ans.begin(),ans.end(),cmp0);
	getans(0);
	sort(ans.begin(),ans.end(),cmp1);
	getans(1);
	sort(ans.begin(),ans.end(),cmp2);
	getans(2);
	sort(ans.begin(),ans.end(),cmp3);
	getans(3);
	for(int i=0;i<m;i++){
		scanf("%d",&name);
		if(st.count(name)==0) printf("N/A\n");
		else printf("%d %c\n",ans[mp[name]].a,cla[ans[mp[name]].a]);
	}
	return 0;
}
