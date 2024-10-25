#include<cstdio>
#include<climits>
#include<cstring>
int N;
int minn=INT_MAX,maxn=INT_MIN;
int h,hh,m,mm,s,ss;
char op[15],lo[15];
int main(){
	scanf("%d",&N);
	char temp[15];
	for(int i=0;i<N;i++){
		scanf("%s %d:%d:%d %d:%d:%d\n",temp,&h,&m,&s,&hh,&mm,&ss);
		if(minn>h*3600+m*60+s){
			minn=h*3600+m*60+s;
			strcpy(op,temp);
		}
		if(maxn<hh*3600+mm*60+ss){
			maxn=hh*3600+mm*60+ss;
			strcpy(lo,temp);
		}
	}
	printf("%s %s",op,lo);
	return 0;
}
