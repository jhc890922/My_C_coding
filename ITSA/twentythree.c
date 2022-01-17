#include<stdio.h>

int gcd(int num1,int num2){
    int ans=0;
    for(int i=1;i<num1;i++){
        if(num1%i==0&&num2%i==0){
            ans=i;
        }
    }
    return ans;
}

int main(){
    int num1;
    int num2;
    int tmp;
    scanf("%d %d",&num1,&num2);
    if(num2>num1){
        tmp=num1;
        num1=num2;
        num2=tmp;
    }
    printf("%d\n",gcd(num1,num2));

}