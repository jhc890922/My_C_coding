#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*int cmp(const void* a,const void* b){
    return (*(int*)a>=*(int*)b)?1:0;
}*/

int sort(int* score_board,int num){
    int tmp;
    for(int i=0;i<num;i++){
        for(int j=i;j<num;j++){
            if(*(score_board+i)>*(score_board+j)){
                tmp = *(score_board+i);
                *(score_board+i) = *(score_board+j);
                *(score_board+j) = tmp;
            }
        }
    }
}


int main(){
    int number = 0;             //上面文字"程式"寫錯，不知道484故意ㄉ
    int* score_board;
    
    scanf("%d\n",&number);
    score_board = malloc(sizeof(int)*(number));
    for(int num_count = 0; num_count < number; num_count++){
        scanf("%d",(score_board+num_count));
    }

    //qsort(score_board,number,sizeof(int),cmp);          // 由小到大排

    //printf("%d %d\n",*score_board,*(score_board + number-1));
    /*for(int i=0;i<10;i++){
        printf("%d ",*(score_board+i));
    }*/

    sort(score_board,number);
    
    int mid = number/2;
    int* team_score_board;
    team_score_board = malloc(sizeof(int)*mid);
    
    for(int team_count = 0; team_count < mid; team_count++){
        *(team_score_board + team_count) = *(score_board + team_count) + *(score_board + number - team_count - 1);
        //printf("%d = %d + %d\n",*(team_score_board + team_count),*(score_board + team_count) , *(score_board + number - team_count - 1));
    }

    //qsort(team_score_board,mid,sizeof(int),cmp);        // 由小到大
    sort(team_score_board,mid);

    printf("%d %d",*(team_score_board),*(team_score_board + mid - 1));

    return 0;

}