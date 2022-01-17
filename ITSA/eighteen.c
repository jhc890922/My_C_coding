#include<stdio.h>

int main(){
    int lenth;
    scanf("%d",&lenth);
    lenth*=100;
    if(((10*lenth)%238)!=0){
        printf("%d\n",lenth*10/238+1);
    }
    else{
        printf("%d\n",lenth*10/238+1);
    }
    return 0;
}