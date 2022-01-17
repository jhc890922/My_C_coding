#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char *getword(char* text ,char* word){
    char *ptr;
    char *qtr;
    ptr=text;
    qtr=word;
    while(!isspace(*ptr)&&*ptr){
        *qtr=*ptr;
        ptr++;
        qtr++;
    }
    while(isspace(*ptr)){
        ptr++;
    }
    *qtr='\0';
    if(strlen(word)!=0){
        return ptr;
    }
    else{
        return NULL;
    }
}

int main(){
    char *text;
    char *word;
    text=malloc(sizeof(char)*1024);
    word=malloc(sizeof(char)*1024);
    char *ptr;
    float *stack;
    stack=malloc(sizeof(float)*1024);
    int top=0;
    fgets(text,1024,stdin);
    ptr=text;
    while((ptr=getword(ptr,word))!=NULL){
        if(strcmp(word,"+")==0){
            *(stack+top-2)=*(stack+top-1) + *(stack+top-2);
            top-=1;
            //printf("%f\n",*(stack+top-1));
        }
        else if(strcmp(word,"-")==0){
            *(stack+top-2)=*(stack+top-2) - *(stack+top-1);
            top-=1;
            //printf("%f\n",*(stack+top-1));
        }
        else if(strcmp(word,"*")==0){
            *(stack+top-2)=*(stack+top-1) * *(stack+top-2);
            top-=1;
            //printf("%f\n",*(stack+top-1));
        }
        else if(strcmp(word,"/")==0){
            *(stack+top-2)=*(stack+top-2) / *(stack+top-1);
            top-=1;
            //printf("%f\n",*(stack+top-1));
        }
        else{
            *(stack+top)=atof(word);
            top++;
        }
    }
    printf("%.1lf\n",*(stack+top-1));
    return 0;
}