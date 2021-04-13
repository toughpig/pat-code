//#include<cstdio>
//#include<vector>
//using namespace std;
////静态数组开30个节点最小要2^31数组大小，编译25秒，崩溃 
//const int maxn=1<<5;
////int ans[maxn]={-1};
//vector<int> ans(100000,-1);
//int post[35];
//int in[35];
//int N;
//
//void creat(int postl,int postr,int inl,int inr,int index){
//	if(inl>inr) return;
//	ans[index]=post[postr];
//	int j;
//	for(j=inl;j<=inr;j++){
//		if(in[j]==post[postr])
//			break;
//	}
//	int numl=j-inl;
//	creat(postl,postl+numl-1,inl,j-1,index*2+1);
//	creat(postl+numl,postr-1,j+1,inr,index*2+2);
//}
//int main(){
//	scanf("%d",&N);
//	for(int i=0;i<N;i++){
//		scanf("%d",post+i);
//	}
//	for(int i=0;i<N;i++){
//		scanf("%d",in+i);
//	}
//	creat(0,N-1,0,N-1,0);
//	int cnt=0;
//	for(int i=0;i<ans.size();i++){
//		if(ans[i]!=-1){
//			cnt++;
//			printf("%d",ans[i]);
//			if(cnt<N)
//			printf(" ");
//			else
//			break;
//		}
//	}
//	return 0;
//}

////参考代码 
//此代码对于单边二叉树极端情况出错，或耗时较长，联想到hash，或者用map映射数组下标 
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<int> post, in, level(1<<30, -1);
//void pre(int root, int start, int end, int index) {
//    if(start > end) return ;
//    int i = start;
//    while(i < end && in[i] != post[root]) i++;
//    level[index] = post[root];
//    pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
//    pre(root - 1, i + 1, end, 2 * index + 2);
//}
//int main() {
//    int n, cnt = 0;
//    scanf("%d", &n);
//    post.resize(n);
//    in.resize(n);
//    for(int i = 0; i < n; i++) scanf("%d", &post[i]);
//    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
//    pre(n-1, 0, n-1, 0);
//    for(int i = 0; i < level.size(); i++) {
//        if (level[i] != -1) {
//            if (cnt != 0) printf(" ");
//            printf("%d", level[i]);
//            cnt++;
//        }
//        if (cnt == n) break;
//    }
//    return 0;
//}
