#include<stdio.h>

int total(int num1,int num2){
    int ans=0;
    for(int i=num1;i<=num2;i++){
        ans+=i;
    }
    return ans;
}

int main(){
    int num1,num2,tmp;
    scanf("%d %d",&num1,&num2);
    if(num2<num1){
        tmp=num2;
        num2=num1;
        num1=tmp;
    }
    printf("%d\n",total(num1,num2));
}