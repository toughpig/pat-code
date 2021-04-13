#include<cstdio>

int main(){
  	float a,b,c;
  	float sum=1.0;
	for(int i=0;i<3;i++){
	scanf("%f %f %f",&a,&b,&c);
	float maxn;
  	maxn=a>b?(a>c?a:c):(b>c?b:c);
  	if(maxn==a)
    	printf("W ");
  	else if(maxn==b)
    	printf("T ");
  	else if(maxn==c)
    	printf("L ");
  	sum*=maxn;
  	}
  	printf("%.2f",(sum*0.65-1)*2);
  	return 0;
}
