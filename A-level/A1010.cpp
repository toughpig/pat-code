#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
vector<int> cmp1,cmp2;
string str1,str2;
int tag,radix;
typedef long long LL;

vector<int> cal(string str,int radix){
	LL temp=0;
	for(int i=0;i<str.size();i++){
		char ch=str[i];
		int n=0;
		if(ch<='9')
			n=ch-'0';
		else
			n=ch-'a'+10;
		temp=temp*radix+n;
	}
	vector<int> vec;
	while(temp!=0){
		vec.push_back(temp%36);
		temp/=36;
	}
	return vec;
}

bool isequl(vector<int> ve1,vector<int> ve2){
	if(ve1.size()!=ve2.size()) return false;
	for(int i=ve1.size()-1;i>=0;i--){
		if(ve1[i]!=ve2[i])
			return false;
	}
	return true;
}

int main(){
	cin>>str1>>str2;
	scanf("%d%d",&tag,&radix);
	if(tag==1){
		cmp1=cal(str1,radix);
		if(str2.size()<cmp1.size()){
				printf("Impossible\n");
				return 0;
			}
		for(int i=2;i<=36;i++){
			cmp2=cal(str2,i);
			if(isequl(cmp1,cmp2)){
				printf("%d",i);
				return 0;
			}
		}
		printf("Impossible\n");
	}
	if(tag==2){
		cmp2=cal(str2,radix);
		if(str1.size()<cmp2.size()){
				printf("Impossible\n");
				return 0;
			}
		for(int i=2;i<=36;i++){
			cmp1=cal(str1,i);
			if(isequl(cmp1,cmp2)){
				printf("%d",i);
				return 0;
			}
		}
		printf("Impossible\n");
	}
	
	return 0;
} 
