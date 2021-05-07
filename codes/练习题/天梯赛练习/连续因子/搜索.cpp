#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll dfs(ll n,ll b,ll len){ //剩余被除数，因子，长度
    if(n%b==0)
        return dfs(n/b,b+1,len+1);
    return len;
}
int main(){
    freopen("in.txt", "r", stdin);

    cin>>n;
    ll len=0;
    ll left=0;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            ll res = dfs(n,i,0);
            if(res>len){
                len=res;
                left=i;
            }
        }
    }
    if(len==0)
        cout<<1<<endl<<n<<endl;
    else{
        cout<<len<<endl;
        for(ll i=1;i<=len;i++){
            if(i==1) cout<<left+i-1;
            else cout<<"*"<<left+i-1;
        }
        cout<<endl;
    }
    return 0;
}
