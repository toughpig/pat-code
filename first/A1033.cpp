#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct gas{
	double price;
	double dist;
	gas(double _p,double _d):price(_p),dist(_d){};
};
bool cmp(gas a,gas b){
	return a.dist<b.dist;
}

vector<gas> station;
double C,D,R,N;
double dd;
double pp;
int main(){
	scanf("%lf%lf%lf%lf",&C,&D,&R,&N);
	for(int i=0;i<N;i++){
		scanf("%lf%lf",&pp,&dd);
		station.push_back(gas(pp,dd));
	}
	station.push_back(gas(0,D));
	sort(station.begin(),station.end(),cmp);
	if(station[0].dist!=0){
	  printf("The maximum travel distance = %.2f",0.0);
	  return 0;
	}
	double road=0.0;
	double nowc=0.0;
	double cost=0.0;
	bool flag=true;
	int i=0;
	while(station[i].dist!=D){
		int minn=-1;
		for(int j=i+1;j<station.size();j++){
			if(station[j].dist-station[i].dist<=C*R&&station[j].price<=station[i].price){
				minn=j;
				break;
			}
		}
		if(minn==-1){
			double p1,d1;
			p1=station[i].price;
			d1=station[i].dist;
			road+=C*R;
			if(station[i+1].dist>road){
				flag=false;
				break;
			}
			else{
				cost+=(C-nowc)*p1;
				road=station[i+1].dist;
				nowc=C-(station[i+1].dist-d1)/R;
				i=i+1;
			}
		}
		else{
			double p1,p2,d1,d2;
			p1=station[i].price;
			p2=station[minn].price;
			d1=station[i].dist;
			d2=station[minn].dist;
			if(1){
				double fill=(d2-d1)/R;
				if(fill>nowc){
					cost+=(fill-nowc)*p1;
					road+=d2-d1;
					nowc=0; 
					i=minn;
				}
				else{
					road+=d2-d1;
					nowc-=(d2-d1)/R;
					i=minn;
				}
			}
		}
	}
	
	if(flag==false)
		printf("The maximum travel distance = %.2lf",road);
	else
		printf("%.2lf",cost);
	return 0;
}
