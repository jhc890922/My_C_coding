#include<stdio.h>

int counting(int num){
    if(num==0){
        return 1;
    }
    else if(num==1){
        return 2;
    }
    else{
        return counting(num-1)+counting(num/2);
    }
}


int main(){
    int num;
    scanf("%d",&num);
    printf("%d\n",counting(num));
    return 0;
}