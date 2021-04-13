#include<cstdio>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<iostream>
using namespace std;
const int maxn=1010;
//char ch[maxn];
string str;
int maxx=1;
int dp[maxn][maxn]={0};

int isrsv(int i,int j){
	if(j-i<=0) return 1;
	else if(str[i]!=str[j]) return 0;
	else return isrsv(i+1,j-1);
}

int main(){
//	gets(ch);
	getline(cin,str);
//	str=ch;
	int len=str.size();
	for(int i=1;i<len;i++){
		for(int j=0;j<len-i;j++){
			dp[j][j+i]=isrsv(j,j+i);
			if(dp[j][j+i]==1)
				maxx=i+1;
		}
	}
	printf("%d",maxx);
	return 0;
}
