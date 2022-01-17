#include<stdio.h>

int main(){

    float num;
    while(scanf("%f",&num)!=EOF){
    printf("%.1f\n",num*1.6);
    }
    return 0;
}