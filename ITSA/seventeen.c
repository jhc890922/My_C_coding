#include<stdio.h>

int main(){
    int num;
    int ten,five,one;
    scanf("%d",&num);
    ten=num/10;
    num-=10*ten;
    five=num/5;
    num-=5*five;
    one=num;
    printf("NT10=%d\n",ten);
    printf("NT5=%d\n",five);
    printf("NT1=%d\n",one);
    return 0;
}