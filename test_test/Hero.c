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
    //int now = 0;
    for(int fight = 1; fight < stage;){
        
            if(*(enemy) > *(enemy+fight)){
                *(enemy) += *(enemy+fight);
                //printf("1 : %d = %d\n",*(enemy),*(enemy+fight));
                fight++;
            }
            else if(*(enemy) > *(enemy+fight+1)&&(fight+1)<stage){
                *(enemy) += *(enemy+fight+1);
                //printf("2 : %d = %d\n",*(enemy),*(enemy+fight+1));
                fight += 2;
            }
            else{
                printf("-1");
                return 0;
            }
        
    }

    printf("%d",*(enemy));

}