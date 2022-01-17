#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
    int row_size;
    int col_size;
    int pre_square[1000][1000];

    while(scanf("%d %d",&row_size,&col_size)!=EOF){
        for(int i=0;i<row_size;i++){
            for(int j=0;j<col_size;j++){
                scanf("%d",&pre_square[i][j]);
            }
        }
        for(int i=0;i<col_size;i++){
            for(int j=0;j<row_size;j++){
                printf("%d",pre_square[j][i]);
                if((j+1)!=row_size){
                    printf(" ");
                }
            }
            printf("\n");
        }
        memset(pre_square,0,sizeof(pre_square));
    }
    return 0;
}