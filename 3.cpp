#include<cstdio>

using namespace std;

int solve(int cc){
    long long a,b;
    scanf("%lld %lld",&a,&b);

    long long s=a+b;
    if(a<b){
        long long t=a;
        a=b;
        b=t;
    }

    long long sol=1;
    for(long long i=s;i>a;i--){
        sol*=(i);
    }
    for(long long i=1;i<=b;i++){
        sol/=i;
    }
    printf("%lld\n",sol);

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
