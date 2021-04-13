#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
map<string,int> Map;
map<string,int>::iterator it;
int main(){
	
	string str;
	getline(cin,str);
	string temp;
	int len=str.length();
	for(int i=0;i<len;i++){
		if(str[i]<='9'&&str[i]>='0'||str[i]>='a'&&str[i]<='z'||str[i]<='Z'&&str[i]>='A'){
			if(str[i]>='A'&&str[i]<='Z'){
				str[i]=str[i]-'A'+'a';
				temp+=str[i];
			}
			else
				temp+=str[i];
		}
		else if(temp.length()>0){
			Map[temp]++;
			temp.clear();
		}
	}
	if(temp.length()>0){
		Map[temp]++;
	}
	string ans;
	int maxn=-1;
	for(it=Map.begin();it!=Map.end();it++){
		if(maxn<it->second){
			maxn=it->second;
			ans=it->first;
		}
	}
	printf("%s %d",ans.c_str(),Map[ans]);
	
	

	return 0;
}

