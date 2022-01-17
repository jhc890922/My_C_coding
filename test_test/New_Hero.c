#include<stdio.h>
#include<stdlib.h>


//先用簡單的方法

int main(){
    
    int stage = 0;
    int* enemy;
    

    scanf("%d",&stage);
    enemy = malloc(sizeof(int)*stage);

    for(int enemy_count = 0; enemy_count < stage; enemy_count++){
        scanf("%d",(enemy+enemy_count));
    }

    int now = *(enemy+stage-1);
    for(int fight = 1; fight < stage;){
        
            /*if(now >= *(enemy)){
                //printf("%d >= %d",now,*(enemy));
                printf("-1");
                return 0;
            }*/
            if(*(enemy+stage-1-fight)>=*(enemy+stage-2-fight)){
                now += *(enemy+stage-2-fight);
                //printf("1 : %d = %d\n",now,*(enemy+stage-2-fight));
                fight += 2;
            }
            else if(*(enemy+stage-1-fight)<*(enemy+stage-2-fight)){
                now += *(enemy+stage-1-fight);
                //printf("2 : %d = %d\n",now,*(enemy+stage-1-fight));
                fight += 1;
            }

            if(((stage-1-fight) <= 0 || (stage-2-fight) <= 0) && (*enemy - now) > 0){
                printf("%d",*enemy - now);
                break;
            }
            else if((*enemy - now) <= 0){
                //printf("%d   %d",(stage-1-fight),(stage-2-fight));
                printf("-1");
                return 0;
            }

        
    }

    //printf("%d",*(enemy));

}