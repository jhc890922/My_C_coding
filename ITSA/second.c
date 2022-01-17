#include<stdio.h>

int main(){
    int x;
    int y;
    while(scanf("%d %d",&x,&y)!=EOF){
        if((x*x+y*y)>40000){
            printf("outside\n");
        }
        else{
            printf("inside\n");
        }
    }
    return 0;
    
}