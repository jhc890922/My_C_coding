#include<stdio.h>

int moded(int num){
    int ans=0;
    for(int i=1;i<=num;i++){
        if(i%2==0&&i%3==0&&i%12!=0){
            ans+=i;
        }
    }
    return ans;
}

int main(){
    int num;
    scanf("%d",&num);
    printf("%d\n",moded(num));
    return 0;
}