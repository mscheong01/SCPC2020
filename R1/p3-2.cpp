//second attempt- got 79points (2/3 partial points)
//coded as O(nk) but doesn't work-> cant understand why :(
#include<iostream>
using namespace std;

int fw[1510][1510];
int sel[1510][2];
int past[1510][1510];

int main(){
    int T;
    cin>>T;
    for(int tc=0;tc<T;tc++){
        int n,k,m;
        cin>>n>>k>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                fw[i][j]=9999;
                past[i][j]=9999;
                if(i==j){
                    fw[i][j]=0;
                    past[i][j]=0;
                }
            }
        }
        for(int i=0;i<k;i++){
            int h1,h2;
            cin>>h1>>h2;
            for(int j=1;j<=n;j++){
                if(past[j][h1]>=past[j][h2]){
                    fw[j][h1]=past[j][h2];
                    sel[j][0]++;
                    
                }
                if(past[j][h2]>=past[j][h1]){
                    fw[j][h2]=past[j][h1];
                    sel[j][1]++;
                }
                if(sel[j][0]==0) fw[j][h1]++;
                
                if(sel[j][1]==0) fw[j][h2]++;
                
                    
                
            }
            for(int j=1;j<=n;j++){
                past[j][h1]=fw[j][h1];
                past[j][h2]=fw[j][h2];
                sel[j][0]=0;
                sel[j][1]=0;
            }
        }
        int sum=0;
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            if(fw[a][b]<3000){
                sum+=fw[a][b];
            }
            else sum+=-1;
        }
        cout<<"Case #"<<tc+1<<endl;
        cout<<sum<<endl;
    
    }
}