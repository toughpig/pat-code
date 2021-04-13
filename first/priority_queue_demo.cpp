#include<queue>
#include<cstdio>
using namespace std;


priority_queue<int,vector<int>,less<int> > q;


int main(){
	
	q.push(2);
	q.push(1);
	q.push(3);
	printf("%d",q.top());
	q.pop();
	printf("%d",q.top());
	q.pop();
	printf("%d",q.top());
	q.pop();
	return 0;
}
