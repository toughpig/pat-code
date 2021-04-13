#include<map>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int st=8*3600;
const int en=17*3600;
vector<pair<int,int> >  ve;
vector<pair<bool,int> > window;
int N,K,h,m,s,t;
int cnt=0,dela=0;
int now;

int findp1(){
	int index=-1;
	int minn=3600;
	for(int i=0;i<window.size();i++){
		if(window[i].first==false)
			return i;
		else{
			if(window[i].second<minn){
				index=i;
				minn=window[i].second;
			}
		}
	}
	return index;
}
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first<b.first;
}
void pro(int k){
	for(int i=0;i<window.size();i++){
		if(window[i].second<=k){
			window[i].first=false;
			window[i].second=now;
		}
	}
}
int main(){
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		if(i<K)
			window.push_back(make_pair(false,st));
		scanf("%02d:%02d:%02d %d",&h,&m,&s,&t);
		if(h*3600+m*60+s<=en)
			ve.push_back(make_pair(h*3600+m*60+s,t*60));
	}
	sort(ve.begin(),ve.end(),cmp);
	int p1=0,p2=0;
	now=st;
	for(int i=0;i<ve.size();i++){
		p1=findp1();
		p2=i;
		if(window[p1].first==true&&window[p1].second>en)
			break;
		else if(window[p1].first==false){
			if(ve[p2].first<now){
				cnt++;
				dela+=now-ve[p2].first;
				window[p1].first=true;
				window[p1].second=now+ve[p2].second;
				continue;
			}
			window[p1].first=true;
			window[p1].second=ve[p2].first+ve[p2].second;
			cnt++;
		}
		else if(window[p1].second<=ve[p2].first){
			now=ve[p2].first;
			pro(now);
			cnt++;
			window[p1].first=true;
			window[p1].second=ve[p2].first+ve[p2].second;
		}
		else if(window[p1].first==true&&window[p1].second>ve[p2].first){
			now=window[p1].second;
			pro(now);
			window[p1].first=true;
			cnt++;
			dela+=now-ve[p2].first;
			window[p1].second=now+ve[p2].second;
		}
	}
	printf("%.1f",(float)dela/60.0/cnt);
	return 0;
}
