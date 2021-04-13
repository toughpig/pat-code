#include<cstdio>
#include<algorithm>
struct node{
	char ch;
	int next;
}letter[100000];

int getlen(int k){
	int first =k;
	int cnt=0;
	while(first!=-1){
		cnt++;
		first=letter[first].next;
	}
	return cnt;
}
int find(int L,int t,int k){
	int p1=t;
	int p2=L;
	int pos=p2;
	for(int i=0;i<k;i++){
		p1=letter[p1].next;
	}
	while(p2!=-1){
		if(p2!=p1){
			p1=letter[p1].next;
			p2=letter[p2].next;
			pos=p2;
		}
		else{
			p1=letter[p1].next;
			p2=letter[p2].next;
		}
	}
	return pos;
	
}

int main(){
	int N,l1,l2;
	scanf("%d %d %d",&l1,&l2,&N);
	for(int i=0;i<N;i++){
		int ad,adn;
		char c;
		scanf("%d %c %d",&ad,&c,&adn);
		letter[ad].ch=c;
		letter[ad].next=adn;
	}
	int len1=getlen(l1);
	int len2=getlen(l2);
	int ans;
	if(len1>len2){
		ans=find(l2,l1,len1-len2);
	}
	else{
		ans=find(l1,l2,len2-len1);
	}
	if(ans!=-1)
	printf("%05d",ans);
	else
	printf("-1");
	
	
	return 0;
}
