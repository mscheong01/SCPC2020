//An alternative correct solution for p3 given to me by my friend SangWon Lee of Seoul Nat Univ.


#include <stdio.h>
#include <iostream>
#define max2(a,b) (a>b ? a:b)
#define INF 987654321

using namespace std;

int a[1501];
int d[1501][1501];

int main(void){
   int tc;
   scanf("%d",&tc);
   for(int tt=0;tt<tc;tt++){
      int n,k,m;
      scanf("%d %d %d",&n,&k,&m);
      
      for(int i=1;i<=n;i++) a[i]=i;
      for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++) d[i][j]=INF;
      }
      
      for(int i=1;i<=n;i++) d[i][i]=0;
      
      for(int i=0;i<k;i++){
         int x,y;
         scanf("%d %d",&x,&y);
         d[a[x]][a[y]]=d[a[y]][a[x]]=1;
      /*   for(int j=1;j<=n;j++){
            for(int l=1;l<=n;l++) printf("%d ",d[j][l]);
            printf("\n");
         }
         printf("?%d %d %d\n",i,a[x],a[y]);*/
         for(int j=1;j<=n;j++){
            if(a[x]==j || a[y]==j) continue;
            if(d[j][a[x]] > d[j][a[y]] + d[a[y]][a[x]]){
               d[j][a[x]] = d[j][a[y]] + d[a[y]][a[x]];
            }
            if(d[j][a[y]] > d[j][a[x]] + d[a[x]][a[y]]){
               d[j][a[y]] = d[j][a[x]] + d[a[x]][a[y]];
            }
         }
         int t;
         t=a[x];
         a[x]=a[y];
         a[y]=t;
      }
      
      /*
      for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
            printf("%d ",d[i][j]);
         }
         printf("\n");
      }
      
      printf("!!\n");
      
      for(int i=1;i<=n;i++) printf("%d ",a[i]);
      printf("\n");
      */
      int sum=0;
      for(int i=0;i<m;i++){
         int x,y;
         scanf("%d %d",&x,&y);
         if(d[x][a[y]]==INF) sum--;
         else sum+=d[x][a[y]];
      //   printf("!%d %d %d\n",a[y],d[x][a[y]],sum);
      }
      
      cout << "Case #" << tt+1 << endl;
      cout << sum << endl;
   }
   return 0;
}