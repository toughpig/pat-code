#include<cstdio>
// void judge(char a,char b,int aw[]){
//   if(a=='B'){
//     if(b=='C'){
//       aw[0]++;
//       aw[2]++;
//     }
//     if(b=='J'){
//       aw[1]++;
//       aw[7]++;
//     }
//   }
//   else if(a=='C'){
//     if(b=='B'){
//       aw[1]++;
//       aw[5]++;
//     }
//     if(b=='J'){
//       aw[0]++;
//       aw[3]++;
//     }
//   }
//   else if(a=='J'){
//     if(b=='B'){
//       aw[0]++;
//       aw[4]++;
//     }
//     if(b=='C'){
//       aw[1]++;
//       aw[6]++;
//     }
//   }
// }
int main(){
  int aw[4]={0};
  int bw[4]={0};
  char a,b;
  int N;
  scanf("%d",&N);
  int n=N;
  getchar();//能读换行
  while(n--){
  	scanf("%c %c",&a,&b) ;
  	getchar();
//  	a=getchar(); 
//  	getchar();//能读空格 
//  	b=getchar();
//  	getchar();
    if(a!=b){
      if(a=='B'){
        if(b=='C'){
          aw[0]++;
          aw[1]++;
        }
        else{
          bw[0]++;
          bw[3]++;
        }
      }
      if(a=='C'){
        if(b=='B'){
          bw[0]++;
          bw[1]++;
        }
        else{
          aw[0]++;
          aw[2]++;
        }
      }
      if(a=='J'){
        if(b=='C'){
          bw[0]++;
          bw[2]++;
        }
        else{
          aw[0]++;
          aw[3]++;
        }
      }
      
    }
    
    // judge(a,b,aw);//0aw 1bw 2aB 3aC 4aJ
  }
  printf("%d %d %d\n%d %d %d\n",aw[0],N-aw[0]-bw[0],bw[0],bw[0],N-aw[0]-bw[0],aw[0]);
  aw[1]>=aw[2]?(aw[1]>=aw[3]?printf("%c ",'B'):printf("%c ",'J')):(aw[2]>=aw[3]?printf("%c ",'C'):printf("%c ",'J'));
  bw[1]>=bw[2]?(bw[1]>=bw[3]?printf("%c",'B'):printf("%c",'J')):(bw[2]>=bw[3]?printf("%c",'C'):printf("%c",'J'));
  
  return 0;
}

