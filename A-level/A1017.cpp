#include<cstdio>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int N,K;
vector<pair<int,int> > window;
vector<pair<int,int> > ve;
int past=8*60*60;
int cnt=0;
int dela=0;
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first<b.first;
}
int isfree(int k){
	for(int i=0;i<k;i++)
		if(window[i].second<=0)
			return i;
	return -1;
}
void pro(int t,int k){
	for(int i=0;i<k;i++){
		window[i].second-=t;
	}
}
int findquic(int k){
	int min=61*60;
	int index=-1;
	for(int i=0;i<k;i++){
		if(window[i].second<min){
			min=window[i].second;
			index=i;
		}
	}
	return index;
}
int main(){
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		if(i<K)
		window.push_back(make_pair(8*60*60,0));
		int h,m,s,l;
		scanf("%02d:%02d:%02d %d",&h,&m,&s,&l);
		if(h*3600+m*60+s<=17*3600)
		ve.push_back(make_pair(h*60*60+m*60+s,l*60));
	}
	sort(ve.begin(),ve.end(),cmp);
	for(int i=0;i<ve.size();i++){
		int temp=ve[i].first;
		temp-=past;
		if(temp>0){
			pro(temp,K);
			past+=temp;
		}
		int win=isfree(K);
		if(win!=-1&&temp>=0){
			window[win]=ve[i];
			cnt++;
			past=window[win].first;
		}
		else if(win!=-1&&temp<0){
			window[win]=make_pair(past,ve[i].second);
			cnt++;
			dela+=past-ve[i].first;
		}
		else{
			int quic=findquic(K);
			past+=window[quic].second;
			pro(window[quic].second,K);
			if(past>17*60*60) break;
			dela+=past-ve[i].first;
			window[quic]=make_pair(past,ve[i].second);
			cnt++;
		}
	}
	if(cnt!=0)
	printf("%.1lf",(double)dela/(double)cnt/60.0);
	else
	printf("0.0");
	return 0;
}
