#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;
bool isdig(char ch){
	if(ch>'9'||ch<'0')
	return false;
	return true;
}

bool islegal(string s){
	int flag=true;
	int len=s.size();
	int st=0;
	if(!isdig(s[0])&&s[0]!='-'&&s[0]!='+'){
		return false;
	}
	else if(s[0]=='-'||s[0]=='+')
		st++;
	if(s[st]=='.') return false;
	for(int i=st;i<len;i++){
		if(!isdig(s[i])&&s[i]!='.')
			return false;
		if(s[i]=='.'&&flag){
			flag=false;
			st=i;
			break;	
		}	
	}
	if(flag==false){
			int kk=0;
			for(int j=st+1;j<len;j++){
				if(!isdig(s[j]))
					return false;
				kk++;
				if(kk>2)
					return false;
			}
			if(kk==0)
			return false;
	}
	return true;
}

int main(){
	int N;
	int cnt=0;
	double sum=0.0;
	string str;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		cin>>str;
		if(islegal(str)){
			double temp;
			sscanf(str.c_str(),"%lf",&temp);
			if(temp>1000||temp<-1000)
				printf("ERROR: %s is not a legal number\n",str.c_str());
			else{
			sum+=temp;
			cnt++;
		}
		}
		else
			printf("ERROR: %s is not a legal number\n",str.c_str());
	}
	if(cnt>1)
	printf("The average of %d numbers is %.2lf",cnt,sum/(double)cnt);
	else if(cnt==1)
	printf("The average of %d number is %.2lf",cnt,sum/(double)cnt);
	else
	printf("The average of %d numbers is Undefined",cnt);
	
	return 0;
}
