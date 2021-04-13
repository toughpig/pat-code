//×Ö·û´®´¦Àí
//#include<cstdio>
#include<string>
#include<iostream>
//#include<algorithm>
using namespace std;
//
//const int maxn=1000;
//
//string str[maxn];
//char temp[100];

//int main(){
//	int cnt=0;
//	while(scanf("%s",temp)!=EOF){
//		str[cnt++]=temp;
//	}
//	for(int i=cnt-1;i>=0;i--){
//		if(i==cnt-1) cout<<str[i];
//		else cout<<" "<<str[i];
//	}
//	return 0;
//} 

#include<stdio.h>
#include<string.h>
int main(){
  	string ch;
  	getline(cin,ch);
  	char sp[85][85];
 	int len=strlen(ch.c_str());
  	int row=0,col=0;
  	for(int i=0;i<len;i++){
    	if(ch[i]!=' '){
      		sp[row][col++]=ch[i];
    	}
		else{
      		sp[row][col]='\0';
      		row+=1;
      		col=0;
    	}
  	}
  	printf("%s",sp[row]);
  	for(int i=row-1;i>=0;i--){
    	printf(" %s",sp[i]);
  	}
  	return 0;
}
