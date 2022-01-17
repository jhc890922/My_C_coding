#include<stdio.h>

int modable(int num){
    int ans=0;
    for(int i=1;i<=num;i++){
        if(i%3==0){
            ans+=i;
        }
    }
    return ans;
}


int main(){
    int num;
    while(scanf("%d",&num)!=EOF){
        printf("%d\n",modable(num));
    }
    return 0;
}