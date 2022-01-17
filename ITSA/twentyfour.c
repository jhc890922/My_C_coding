#include<stdio.h>

int main(){
    int min;
    double ans;
    scanf("%d",&min);
    if(min<=800){
        ans=min*0.9;
    }
    else if(min>800&&min<1500){
        ans=min*0.9*0.9;
    }
    else{
        ans=min*0.9*0.79;
    }
    printf("%.1f\n",ans);
    return 0;
}