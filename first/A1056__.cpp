#include<stdio.h>
#include<string.h>  //��memset()����
const int MAX=1010;
int mouse[MAX],order[MAX],rank[MAX];
bool mark[MAX],flag;  //mark[]=1��ǰ��ߣ�flag=1���ʣ���һ�飨���������Ҳ���ԣ�
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
		flag=1; memset(mark,0,sizeof(mark));memset(rank,-1,sizeof(rank));  //ȫ�ֱ�����ʼ��
		while(flag){  //��һ��ͨ��������ֻʣһ������
			if(group==1)  //���ֽ�������ִ��while()ѭ��
				flag=0;
			cnt=0;max=-1;maxid=-1;  //cntͳ��ÿng����ʼ��һ��
			for(i=0;i<np;i++){
				if(mark[order[i]]==0){
					if(cnt==ng){   //����ͳ�Ƹ�����ÿng����ʼ��һ��
						max=mouse[order[i]];maxid=order[i];cnt=0;  //cnt��0��������������
						cnt++;
						continue;
					}
					cnt++;
					if(mouse[order[i]]>max){//��֮ǰ��Ϊ�����ֵ���Ǹ����б�ǣ������������������ֵ���±�
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
