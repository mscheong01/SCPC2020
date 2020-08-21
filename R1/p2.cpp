//correct
#include<iostream>

using namespace std;
int a[3010],b[3010],dp[3010][3010];
int main()
{
    int T;
    cin>>T;
    for(int tc=0;tc<T;tc++){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        dp[0][0]=1;
        int a1=0,a2=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(dp[i][j]!=0){
                    a1++;
                    continue;
                } 
                int sumx=0,sumy=0,xp=i,yp=j;
                bool flag=true;
                // while(flag){
                //     sumx+=a[xp-1];
                //     xp--;
                //     if(sumx>k||xp<0){
                        
                //         break;
                //     }
                //     if(!dp[xp][j]){
                //         flag=false;
                //         break;
                //     }
                // }
                
                // while(flag){
                //     sumy+=b[yp-1];
                //     yp--;

                //     if(sumy>k||yp<0){
                //         break;
                //     }
                //     if(!dp[i][yp]){
                //         flag=false;
                //         break;
                //     }
                // }

                if(flag){
                    a2++;
                    dp[i][j]=0;
                    sumx=0;
                    sumy=0;
                    xp=i;
                    yp=j;
                    //cout<<"]"<<i<<","<<j<<endl;
                    while(true){
                        xp++;
                        if(xp>n) break;
                        sumx+=a[xp-1];
                        if(sumx>k) break;
                        dp[xp][j]=1;
                    }
                    while(true){
                        yp++;
                        if(yp>n) break;
                        sumy+=b[yp-1];
                        if(sumy>k) break;
                        dp[i][yp]=1;
                    }
                }
                // else{
                //     a1++;
                //     dp[i][j]=1;
                //     cout<<"["<<i<<","<<j<<endl;
                // }
            }
        }
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=0;
            }
        }
        cout<<"Case #"<<tc+1<<endl;
        cout<<a1<<" "<<a2<<endl;
    }
}