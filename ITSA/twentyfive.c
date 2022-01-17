#include<stdio.h>

long long int fac(int num){
    long long int ans=1;
    for(int i=1;i<=num;i++){
        ans*=i;
    }
    return ans;
}


int main (){
    long long int num;
    scanf("%lld",&num);
    printf("%lld\n",fac(num));
    return 0;
}