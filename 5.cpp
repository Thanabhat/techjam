#include<cstdio>
#include<iostream>
#include<vector>
#include <sstream>

using namespace std;

string str;
int dat[100005];
int dp[100005];

int solve(int cc){
    cin>>str;
    vector<int> v;
    stringstream ss(str);
    int ii;
    while(ss>>ii){
        v.push_back(ii-1);
        if(ss.peek()==','){
            ss.ignore();
        }
    }

    int n=v.back()+1;
    for(int i=0;i<n;i++){
        dat[i]=0;
        dp[i]=0;
    }
    for(int i=0;i<v.size();i++){
        dat[v[i]]=1;
    }
    for(int i=0;i<n;i++){
        if(dat[i]){
            int c1,c7,c30;
            if(i-1>=0){
                c1=dp[i-1]+2;
            }else{
                c1=2;
            }
            if(i-7>=0){
                c7=dp[i-7]+7;
            }else{
                c7=7;
            }
            if(i-30>=0){
                c30=dp[i-30]+25;
            }else{
                c30=25;
            }
            int mn=min(c1,min(c7,c30));
            dp[i]=mn;
        }else{
            if(i==0){
                dp[i]=0;
            }else{
                dp[i]=dp[i-1];
            }
        }
    }
    cout<<dp[n-1]<<endl;
    return 1;
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        solve(i+1);
    }
    return 0;
}
