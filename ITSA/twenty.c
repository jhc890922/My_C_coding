#include<stdio.h>

int main(){
    int input;
    int day;
    int hour;
    int min;
    int sec;
    scanf("%d",&input);
    day=input/86400;
    input%=86400;
    hour=input/3600;
    input%=3600;
    min=input/60;
    input%=60;
    sec=input;
    printf("%d days\n%d hours\n%d minutes\n%d seconds\n",day,hour,min,sec);
    return 0;
    
}