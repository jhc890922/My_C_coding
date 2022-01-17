#include<stdio.h>


int main(){
    float upper;
    float down;
    float hight;
    scanf("%f %f %f",&upper,&down,&hight);
    printf("Trapezoid area:%.1f\n",(upper+down)*hight/2);
    return 0;
}