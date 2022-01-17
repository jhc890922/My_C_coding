#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int main(){

    double input;
    while(scanf("%lf",&input)!=EOF){
        printf("%.1f\n",(1.6*input));
    }
    return 0;
}