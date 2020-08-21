//1st attempt- got 26 points(first partial point)
#include<iostream>
#include<map>
using namespace std;
// int dest(int from,int height,int k,int hor[][2]){
//     int now=from;
//     if(height==k) return now;
//     for(int i=height;i<k;i++){
//         if(hor[i][0]==now){
//             now=hor[i][1];
//         }
//         else if(hor[i][1]==now){
//             now=hor[i][0];
//         }
//     }
    
//     return now;
// }
int dp[1510][2010]={0};

int find(int from,int to, int height,int k,int hor[][2]){
    int ret;
    if(dp[from][height]==to) return 0;
    //if(height==k&&from==to) return 0;
    if(height==k) return 9999;
    int temp[2];
    if(hor[height][0]==from){
        int a=find(hor[height][1],to,height+1,k,hor);
        int b=find(from,to,height+1,k,hor)+1;
        ret=(a<b)?a:b;
    }
    else if(hor[height][1]==from){
        int a=find(hor[height][0],to,height+1,k,hor);
        int b=find(from,to,height+1,k,hor)+1;
        ret=(a<b)?a:b;
    }
    else{
        return find(from,to,height+1,k,hor);
    }
    return ret;
}


int main()
{
    int T;
    cin>>T;
    for(int tc=0;tc<T;tc++){
        int n,k,m;
        int hor[2010][2];
       
        map<int,int> mp[1510];
        cin>>n>>k>>m;
        for(int i=0;i<k;i++){
            int a,b;
            cin>>a>>b;
            hor[i][0]=a;
            hor[i][1]=b;
            
        }
        for(int i=1;i<=n;i++){
            dp[i][k]=i;
        }
        for(int i=k-1;i>=0;i--){
            for(int j=1;j<=n;j++){
                if(hor[i][0]==j){
                    dp[j][i]=dp[(hor[i][1])][i+1];
                }
                else if(hor[i][1]==j){
                    dp[j][i]=dp[(hor[i][0])][i+1];
                }
                else{
                    dp[j][i]=dp[j][i+1];
                }
            }
        }
        
        int sum=0;
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            int tmp;
            tmp=find(a,b,0,k,hor);
            //cout<<">"<<tmp<<endl;
            if(tmp>3000) sum--;
            else sum+=tmp;
        }
        cout<<"Case #"<<tc+1<<endl;
        cout<<sum<<endl;
    }
}