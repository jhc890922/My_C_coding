#include<stdio.h>

int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    if(x*x+y*y<40000){
        printf("inside\n");
    }
    else{
        printf("outside\n");
    }
    return 0;
}