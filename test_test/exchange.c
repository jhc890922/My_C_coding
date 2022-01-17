#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void change(int* table,int a,int b){
    int tmp = *(table+a-1);
    *(table+a-1) = *(table+b-1);
    *(table+b-1) = tmp;
}

int main(){

        int number = 0;
        int switch_num = 0;
        
        scanf("%d %d\n",&number,&switch_num);   // m可能要寫清楚些

        int* card_index;
        card_index = malloc(sizeof(int)*100001);
        for(int member = 0;member < number;member++){
            scanf("%d",(card_index+member));
        }
        

        int exchange[2];
        for(int switch_time = 0;switch_time < switch_num;switch_time++){
            scanf("%d %d",&exchange[0],&exchange[1]);       
            change(card_index,exchange[0],exchange[1]);
        }

        for(int i = 0;i < number;i++){
            printf("%d ",*(card_index+i));
        }
        //printf("\n");
        return 0;
}