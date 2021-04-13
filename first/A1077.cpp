#include<cstdio>
#include<string>
#include<cmath>
#include<iostream> 
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
char a[300];
string temp;
//void findco(char ch1[],char ch2[]){
//	temp.clear();
//	int len=min(strlen(ch1),strlen(ch2));
//	for(int i=0;i<len;i++){
//		int aa=strlen(ch1)-len+i;
//		int bb=strlen(ch2)-len+i;
//		if(ch1[aa]==ch2[bb])
//			temp+=ch1[aa];
//		else{
//			temp.clear();
//		}
//	}
//	strcpy(ch1,temp.c_str());
//}
int main(){
	int N;
	scanf("%d\n",&N);
	for(int i=0;i<N;i++){
		string ch;
		getline(cin,ch);
		if(i==0){
			strcpy(a,ch.c_str());
		}
		temp.clear();
		int len=min(strlen(a),strlen(ch.c_str()));
		for(int i=0;i<len;i++){
			int aa=strlen(a)-len+i;
			int bb=strlen(ch.c_str())-len+i;
			if(a[aa]==ch[bb])
				temp+=a[aa];
			else{
				temp.clear();
			}
		}
		strcpy(a,temp.c_str());
	}
	if(strlen(a)==0)
		printf("nai");
	else
		printf("%s",a);
	return 0;
}
