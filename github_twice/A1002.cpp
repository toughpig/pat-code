//多项式相加，指数Nk<=1000,可开数组
//考虑到如果指数为int范围的话，使用pair映射
#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

#define mp make_pair
#define ff first
#define ss second

vector<pair<int,double> > a,b,ans;

bool cmp(pair<int,double> aa,pair<int,double> bb){
	return aa.ff>bb.ff;
}

int main(){
	int k,p;
	double q;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d%lf",&p,&q);
		a.push_back(mp(p,q));
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d%lf",&p,&q);
		b.push_back(mp(p,q));
	}
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end(),cmp);
	int i=0,j=0;
	while(i<a.size()&&j<b.size()){
		if(a[i].ff==b[j].ff){
			if(a[i].ss+b[j].ss!=0)
				ans.push_back(mp(a[i].ff,a[i].ss+b[j].ss));
			i++;
			j++;
		}
		else if(a[i].ff>b[j].ff){
			ans.push_back(a[i++]);
		}
		else{
			ans.push_back(b[j++]);
		}
	}
	while(i<a.size()) ans.push_back(a[i++]);
	while(j<b.size()) ans.push_back(b[j++]);
	printf("%d",ans.size());
	for(int h=0;h<ans.size();h++){
		printf(" %d %.1lf",ans[h].ff,ans[h].ss);
	}
	return 0;
}
