//onlineÁª»ú
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

string ulock,lock;
int maxn=-1,minn=1<<30;

int h,m,s,tot,M;
char temp[15];

int main(){
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		scanf("%s%02d:%02d:%02d",temp,&h,&m,&s);
		tot=h*3600+m*60+s;
		if(tot<minn){
			minn=tot;
			ulock=temp;
		}
		scanf("%02d:%02d:%02d",&h,&m,&s);
		tot=h*3600+m*60+s;
		if(tot>maxn){
			maxn=tot;
			lock=temp;
		}
	}
	printf("%s %s",ulock.c_str(),lock.c_str());
	return 0;
} 
