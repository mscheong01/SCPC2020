//second attempt- got 79points (2/3 partial points)
//coded as O(nk) but doesn't work-> cant understand why :(
#include<iostream>
using namespace std;

int dp[1510][1510];

int main(){
    int T;
    cin>>T;
    for(int tc=0;tc<T;tc++){
        int n,k,m;
        cin>>n>>k>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=9999;
                if(i==j){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=0;i<k;i++){
            int h1,h2;
            cin>>h1>>h2;
            int temp;
            for(int j=1;j<=n;j++){
                if(dp[j][h1]==dp[j][h2]){
                    temp=dp[j][h1];
                    dp[j][h1]=dp[j][h2];
                    dp[j][h2]=temp;
                }
                else if(dp[j][h1]>dp[j][h2]){
                    temp=dp[j][h1];
                    dp[j][h1]=dp[j][h2];
                    dp[j][h2]++;
                }
                else if(dp[j][h1]<dp[j][h2]){
                    dp[j][h2]=dp[j][h1];
                    dp[j][h1]++;
                }
                
            }
        }
        int sum=0;
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            if(dp[a][b]<3000){
                sum+=dp[a][b];
            }
            else sum+=-1;
        }
        cout<<"Case #"<<tc+1<<endl;
        cout<<sum<<endl;
    
    }
}