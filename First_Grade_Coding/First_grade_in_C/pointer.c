#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    int times;
    int num;
    int i=0,j;
    char *command;
    char **insert;
    char *output;
    //output=malloc(sizeof(char)*1024);
    insert=malloc(sizeof(char*)*1024);
    command=malloc(sizeof(char)*1024);
    scanf("%d",&times);
    while(scanf("%s",command)!=EOF){
        if(strcmp(command,"OUTPUT")==0){
            break;
        }
        else{
            scanf("%d",&num);
            *(insert+i)=malloc(sizeof(char)*num);
            scanf("%s",*(insert+i));
            i++;
        }
        /*for(i=j;i<(times+j);i++){
            scanf("%s%d",command,&num);
            *(insert+i)=malloc(sizeof(char)*1024);
            scanf("%s",*(insert+i));
        printf("%s %d\n",command,num);
        printf("%s\n",*(insert+i));
        printf("%d\n",i);
        }
        j+=times;*/
    }
    for(j=(i-1);j>=0;j--){
        printf("%s\n",*(insert+j));
    }
    return 0;       
}