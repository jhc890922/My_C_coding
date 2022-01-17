#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char *get_string(){
    char* text;
    text=malloc(sizeof(char)*1024);

    if(fgets(text,1024,stdin)!=NULL){
        int lengh=0;
        while(*(text+lengh)!='\n'){
            lengh++;
        }
        if(*(text+lengh)=='\n'){
            *(text+lengh)='\0';
        }
    return text;
    }
    else{
        return NULL;
    }
}

int main(int argc,char **argv){
    char** text;
    text=malloc(sizeof(char*)*100);
    for(int i=0;i<100;i++){
        *(text+i)=malloc(sizeof(char)*1024);
    }
    int times=0;
    *(text+times)=*(argv+1);
    times++;
    while((*(text+times)=get_string())!=NULL){
        times++;
        //printf("%d\n",times);
        //printf("%s",*(text+times-1));
    }
    for(int i=0;i<times;i++){
        printf("%s",*(text+i));
    }
    printf("\n");
    return 0;
}