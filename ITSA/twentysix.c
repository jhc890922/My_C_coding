#include<stdio.h>

int main (){

    int time,payed;
    double payment=0;
    scanf("%d %d",&time,&payed);
    if(time<=60){
        payment=time*payed;
    }
    else if(time>60&&time<=120){
        payment=60*payed;
        time-=60;
        payment=payment+time*payed*1.33;
    }
    else{
        payment=60*payed;
        time-=60;
        payment=payment+60*payed*1.33;
        time-=60;
        payment=payment+time*payed*1.66;
    }
    printf("%.1f\n",payment);
    return 0;
}