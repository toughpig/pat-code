#include<cstdio>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<queue>
#include<deque>
#include<algorithm>
using namespace std;
int main(){
////--------------------------------------------------
////--algorithm
	/*
	do--while(next_permutation(a.begin(),a.end() ) );到达全排列最后一个后返回false 
	
	
	*/
//	string a="123456789";
//	do{
//		puts(a.c_str());
//	}while(next_permutation(a.begin(),a.begin()+4));
////--------------------------------------------------
////--queue
//	deque<int> dq;
//	queue<int> pq;
//	pq.push(2);
//	pq.push(3);
//	pq.push(1);
//	pq.push(4);
//	printf("%d",pq.front());
//	pq.front()=5;
//	printf("\n%d",pq.front());
////-------------------------------------------------
////--map
//	unordered_map<string,int> um;
//	map<string,int> m;
//	um["123"]++;
//	um["345"]++;
//	m["12345"]++;
//	m["45678"]++;
//	m["34567"]++;
//	unordered_map<string,int>::iterator umit;
//	map<string,int>::iterator it;
//	for(umit=um.begin();umit!=um.end();umit++)
//		printf("%s %d\n",(*umit).first.c_str(),(*umit).second);
//	for(it=m.begin();it!=m.end();it++)
//		printf("%s %d\n",(*it).first.c_str(),(*it).second);
//	it=m.find("34567");
//	printf("%s %d",it->first.c_str(),it->second);
////----------------------------------------------------
////--set
//	unordered_set<string> uo_s;
//	set<string> s;
//	uo_s.insert("123");
//	s.insert("345");
//	uo_s.insert("34567");
//	s.insert("123");
//	unordered_set<string>::iterator uo_it;
//	set<string>::iterator it;
//	for(uo_it=uo_s.begin();uo_it!=uo_s.end();uo_it++)
//		puts((*uo_it).c_str());
//	for(it=s.begin();it!=s.end();it++)
//		puts((*it).c_str());
////-------------------------------------------------------
////--string 
//	char ch[10];
//	string a;
////	printf("%d\n",strlen(ch));
////	getline(cin,a);
//	cin>>a;
////	gets(ch);
////	puts(ch);
//	puts(a.c_str());
////	a.reserve(2);
////	puts(a.c_str());
////	printf("%d",strlen(ch));
//	string b;
//	b=a.substr(2,3);
//	puts(b.c_str());
//	int i=a.find("3",2);
//	int j=a.find("3",4);
//	a.replace(i,2,b);
//	puts(a.c_str());
//	printf("%d %d",i,j);
	return 0;
}
