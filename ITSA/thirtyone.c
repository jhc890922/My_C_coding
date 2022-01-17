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
    scanf("%d",&num);
    for(int i=num-1;i>=0;i--){
        if(prime(i)){
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}