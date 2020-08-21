//correct
#include<iostream>
#include<set>
#include<algorithm> 
using namespace std;
int a[200010],b[200010],c[200010];
int main(){
    int T;
    cin>>T;
    for(int tn=0;tn<T;tn++){
        int n,k;
        cin>>n>>k;
        
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        for(int i=0;i<k;i++){
            c[i]=(a[i]+b[k-1-i])*-1;
        }
        sort(c,c+k);
        cout<<"Case #"<<tn+1<<endl;
        cout<<-1*c[0]<<endl;
    }
}
//The code below is the one that I wrote at the beginning, which came out as TLE(2s) with n<=200,000
//This code is theoretically O(nlogn) but as the n gets bigger, the insertion of the multiset seemed to take longer than expected
// int main(){
//     int T;
//     cin>>T;
//     for(int tn=0;tn<T;tn++){
//         int n,k;
//         cin>>n>>k;
//         multiset<int> a,b,c;
//         multiset<int>::iterator a1,b1;
//         int temp;
//         for(int nc=0;nc<n;nc++){
//             cin>>temp;
//             a.insert(temp);
//         }
//         for(int nc=0;nc<n;nc++){
//             cin>>temp;
//             b.insert(temp);
//         }
//         a1=a.begin();
//         b1=b.begin();
//         for(int i=1;i<k;i++){
//             b1++;
//         }
//         for(int i=0;i<k;i++){
//             c.insert(-1*(*a1+*b1));
            
//             a1++;
//             b1--;
//         }
//         cout<<"Case #"<<tn+1<<endl;
//         cout<<-1*(*c.begin())<<endl;
//     }
//     return 0;
// }