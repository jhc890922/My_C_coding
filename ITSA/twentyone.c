#include<stdio.h>

int main(){
    int x,y;
    while(scanf("%d %d",&x,&y)!=EOF){
        if(x<=100&&y<=100){
            printf("inside\n");
        }
        else{
            printf("outside\n");
        }
    }
    return 0;
}