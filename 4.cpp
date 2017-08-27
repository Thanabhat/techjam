#include<cstdio>
#include<functional>

using namespace std;

int solve(int cc){
    int c,r,n;
    scanf("%d %d %d",&c,&r,&n);
    int mx=max(c,r),mn=min(c,r);
    printf("#%d\n",cc);
    bool sol=false;
    if(mn<2){
        if((mx<=2&&n!=0)||(n>mx-2)){
            printf("impossible\n");
            return 1;
        }else{
            int tb[r][c];
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    tb[i][j]=0;
                }
            }
            int cnt=n;
            for(int i=0;i<r&&cnt>0;i++){
                for(int j=0;j<c&&cnt>0;j++){
                    tb[i][j]=1;
                    cnt--;
                }
            }
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(tb[i][j]){
                        printf("*");
                    }else{
                        printf(".");
                    }
                }
                printf("\n");
            }
            return 1;
        }
    }else if(n<=(c-2)*(r-2)){
        int tb[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                tb[i][j]=0;
            }
        }
        int cnt=n;
        for(int i=0;i<r-2&&cnt>0;i++){
            for(int j=0;j<c-2&&cnt>0;j++){
                tb[i][j]=1;
                cnt--;
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(tb[i][j]){
                    printf("*");
                }else{
                    printf(".");
                }
            }
            printf("\n");
        }
        return 1;
    }else{
        int c1,r1,c2,r2;
        for(c1=2;c1<=c&&!sol;c1++){
            for(r1=2;r1<=r&&!sol;r1++){
                for(c2=2;c2<=c&&!sol;c2++){
                    for(r2=2;r2<=r&&!sol;r2++){
                        int sum=c1*r1+c2*r2;
                        sum-=min(c1,c2)*min(r1,r2);
                        if(c*r-sum==n){
                            sol=true;
                        }
                        if(sol){
                            break;
                        }
                    }
                    if(sol){
                        break;
                    }
                }
                if(sol){
                    break;
                }
            }
            if(sol){
                break;
            }
        }
        if(sol){
            int tb[r][c];
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    tb[i][j]=1;
                }
            }
            for(int i=0;i<r1;i++){
                for(int j=0;j<c1;j++){
                    tb[r-i-1][c-j-1]=0;
                }
            }
            for(int i=0;i<r2;i++){
                for(int j=0;j<c2;j++){
                    tb[r-i-1][c-j-1]=0;
                }
            }
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(tb[i][j]){
                        printf("*");
                    }else{
                        printf(".");
                    }
                }
                printf("\n");
            }
            return 1;
        }else{
            printf("impossible\n");
            return 1;
        }
    }
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
