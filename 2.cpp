#include<cstdio>
#include<vector>

#define pii pair<int,int>

using namespace std;

int tar[1050][1050];
int tb[1050][1050];
int qs1[1050][1050];
int qs2[1050][1050];

int solve(int cc){
    vector<pair<pii, int> > sol;
    int c,r;
    scanf("%d %d",&c,&r);
    int tmp;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&tar[i][j]);
            tb[i][j]=0;
        }
    }
    bool solve=false;
    int rc = r*c;
    int cntT = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(tar[i][j]==tb[i][j]){
                cntT++;
            }
        }
    }

    int globalMaxN=2000;
    while(!solve){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(j>0){
                    qs1[i][j]=qs1[i][j-1];
                }else{
                    qs1[i][j]=0;
                }
                qs1[i][j]+=(tar[i][j]==tb[i][j])?0:1;

                if(i==0){
                    qs2[i][j]=qs1[i][j];
                }else{
                    qs2[i][j]=qs1[i][j]+qs2[i-1][j];
                }
            }
        }

        int nexti=0,nextj=0,nextn=0,nextchg=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                for(int n=0;i+n<r&&j+n<c&&n<=globalMaxN;n++){
                    if((n+1)*(n+1)/2>rc-cntT){
                        break;
                    }

                    int sum=qs2[i+n][j+n];
                    if(i>0){
                        sum-=qs2[i-1][j+n];
                    }
                    if(j>0){
                        sum-=qs2[i+n][j-1];
                    }
                    if(i>0&&j>0){
                        sum+=qs2[i-1][j-1];
                    }
                    int chg = sum-((n+1)*(n+1)-sum);
                    if(chg>nextchg){
                        nexti=i;
                        nextj=j;
                        nextn=n;
                        nextchg=chg;
                    }
                }
            }
        }

        sol.push_back(pair<pii, int>(pii(nextj+1,nexti+1), nextn+1));
        for(int i=nexti;i<=nexti+nextn;i++){
            for(int j=nextj;j<=nextj+nextn;j++){
                tb[i][j]+=1;
                tb[i][j]%=2;
            }
        }
        cntT+=nextchg;
        
        if(cntT==rc){
            solve=true;
            break;
        }
        globalMaxN=nextn;
    }
    printf("%d\n",sol.size());
    for(int i=0;i<sol.size();i++){
        printf("%d,%d %d\n",sol[i].first.first,sol[i].first.second,sol[i].second);
    }
    return 1;
}

int main() {
    int n;
    scanf("%d",&n);
    printf("%d\n",n);
    for(int i=0;i<n;i++){
        solve(i+1);
    }
    return 0;
}
