#include<cstdio>

using namespace std;

int solve(int cc){
    int a,b;
    scanf("%d+%d",&a,&b);
    printf("%d\n",a+b);
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
