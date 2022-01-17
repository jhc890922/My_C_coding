#include<stdio.h>

int prime(int num){
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}


int main(){
    int num;
    while(scanf("%d",&num)!=EOF){
        if(prime(num)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}