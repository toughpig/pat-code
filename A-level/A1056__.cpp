#include<stdio.h>
#include<string.h>  //用memset()函数
const int MAX=1010;
int mouse[MAX],order[MAX],rank[MAX];
bool mark[MAX],flag;  //mark[]=1标记败者；flag=1标记剩最后一组（分情况讨论也可以）
int main()
{	
	int	np,ng,i,max,maxid,cnt;
    //freopen("G:\\in.txt","r",stdin);
	while(scanf("%d%d",&np,&ng)!=EOF){
		for(i=0;i<np;i++)
			scanf("%d",&mouse[i]);
		for(i=0;i<np;i++)
			scanf("%d",&order[i]);
		int group=(np%ng==0)?(np/ng):(np/ng+1);
		flag=1; memset(mark,0,sizeof(mark));memset(rank,-1,sizeof(rank));  //全局变量初始化
		while(flag){  //用一种通法巧妙处理好只剩一组的情况
			if(group==1)  //本轮结束后不再执行while()循环
				flag=0;
			cnt=0;max=-1;maxid=-1;  //cnt统计每ng个初始化一次
			for(i=0;i<np;i++){
				if(mark[order[i]]==0){
					if(cnt==ng){   //首先统计个数，每ng个初始化一次
						max=mouse[order[i]];maxid=order[i];cnt=0;  //cnt清0！！！！！！！
						cnt++;
						continue;
					}
					cnt++;
					if(mouse[order[i]]>max){//把之前认为是最大值的那个进行标记，给出排名并更新最大值和下标
						mark[maxid]=1;
						rank[maxid]=group+1;
						maxid=order[i];
						max=mouse[order[i]];
					}
					else{
						rank[order[i]]=group+1;
						mark[order[i]]=1;
					}
				}
			}
			group=(group%ng==0)?(group/ng):(group/ng+1);
		}
		rank[maxid]=1;
		for(i=0;i<np;i++){
			if(i!=0) printf(" ");
			printf("%d",rank[i]);
		}
		printf("\n");
	}
 
    return 0;
}
