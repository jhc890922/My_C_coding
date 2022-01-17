#include<stdio.h>

int main(){
    int in_hour,out_hour;
    int in_min,out_min;
    int total_min;
    int ans=0;
    scanf("%d %d",&in_hour,&in_min);
    scanf("%d %d",&out_hour,&out_min);
    if(in_min>out_min){
        out_hour--;
        out_min+=60;
    }
    total_min=60*(out_hour-in_hour)+out_min-in_min;
    if(total_min<120){
        ans=(total_min/30)*30;
    }
    else if(total_min>=120&&total_min<240){
        ans=((total_min-120)/30)*40+120;
    }
    else if(total_min>=240){
        ans=((total_min-240)/30)*60+280;
    }
    printf("%d\n",ans);
    return 0;
}