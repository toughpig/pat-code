#include<cstdio>

int main(){
	int cnt=0;
	int num;
	scanf("%d",&num);
	while(num!=1){
    	if(num%2){
    		num=(num*3+1)/2;
    		cnt++;
    	}
    	else{
    		num/=2;
    		cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
