#include<stdio.h>


int prime(long long int num){
    for(long long int i=2;i*i<=num;i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    long long int num;
    scanf("%lld",&num);
    if(prime(num)){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}