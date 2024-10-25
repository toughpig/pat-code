#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
char ch[31];
int getnum(int i,int j){
	int ans=0;
	for(int k=i;k<=j;k++){
		ans=ans*10+ch[k]-'0';
	}
	return ans;
}
int main(){
	scanf("%s",ch);
	int sum=0;
	int len=strlen(ch);
	if(ch[0]=='1')
	sum+=getnum(1,len-1)+1;
	else
	sum+=pow(10,len-1);
	for(int i=1;i<len-1;i++){
		int times=getnum(0,i-1);
		if(ch[i]!='0'&&ch[i]!='1')
		times++;
		else if(ch[i]=='1'){
			int back=getnum(i+1,len-1);
			sum+=back+1;
		}
		sum+=pow(10,len-i-1)*times;
	}
	if(len!=1){
		sum+=getnum(0,len-2);
		if(ch[len-1]!='0')
			sum++;
	}
	printf("%d",sum);
	return 0;
}
