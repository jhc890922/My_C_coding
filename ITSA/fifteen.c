#include<stdio.h>

int main(){
    int num;
    scanf("%d",&num);
    if(num>31){
        printf("Value of more than 31\n");
        return 0;
    }
    num=1<<num;
    printf("%d\n",num);
    return 0;
}