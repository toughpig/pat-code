#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int st=8*3600;
const int en=17*3600;
int N,K,h,m,s,t,temp;
struct node{
	int first,second;
	node(int _first,int _second):first(_first),second(_second){};
};
vector<node > ve;
int win[120];
int cnt=0,dela=0;
bool cmp(node a,node b){
	return a.first<b.first;
}
int findp1(){
	int minn=en+1;
	int index=-1;
	for(int i=0;i<K;i++){
		if(win[i]<minn){
			minn=win[i];
			index=i;
		}
	}
	return index;
}
int main(){
	scanf("%d%d",&N,&K);
	fill(win,win+K,st);
	for(int i=0;i<N;i++){
	
		scanf("%02d:%02d:%02d%d",&h,&m,&s,&t);
		temp=h*3600+m*60+s;
		if(t>60)
			t=60;
		if(temp<=en)
			ve.push_back(node(temp,t*60));
	}
	sort(ve.begin(),ve.end(),cmp);
	for(int i=0;i<ve.size();i++){
		temp=findp1();
//		if(win[temp]>en) break;
		if(win[temp]<=ve[i].first){
			cnt++;
//			pro(ve[i].first);
			win[temp]=ve[i].first+ve[i].second;
		}
		else{
			cnt++;
			dela+=win[temp]-ve[i].first;
			win[temp]+=ve[i].second;
		}
	}
	if(cnt!=0)
	printf("%.1f",(float)dela/60.0/cnt);
	else
	printf("0.0");
	return 0;
}
