#include<stdio.h>

int main(){
    int num;
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        if(i%35==0){
            printf("%d",i);
            if(i+35<num){
                printf(" ");
            }
            else{
                printf("\n");
            }
        }
    }
    return 0;
}