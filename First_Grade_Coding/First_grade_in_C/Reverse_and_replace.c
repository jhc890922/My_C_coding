#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int Which_is_Bigger(char *a,char *b){
    if(strcmp(a,b)>0){
        return 1;
    }
    else{
        return 0;
    }
}

char *Combine(char *a,char* b,char *c){
    char *combine;
    combine=malloc(sizeof(char)*101);
    memset(combine,'\0',101);
    strcat(combine,a);
    strcat(combine,b);
    strcat(combine,c);

    return combine;
}

int main(int argc,char** argv){

    char *text;
    char **data_storage;
    text=malloc(sizeof(char)*101);
    data_storage=malloc(sizeof(char*)*30);
    char *ptr,*qtr,*head,*toe;
    char *first;
    char *last;
    first=malloc(sizeof(char)*101);
    last=malloc(sizeof(char)*101);
    int line=0;
    
    while(fgets(text,101,stdin)!=NULL){
        if(*(text+strlen(text)-1)=='\n'){
            *(text+strlen(text)-1)='\0';
        }
       // ptr=strstr(text,*(argv+1));
        head=text;
        toe=(text+strlen(text)-1);
        int swich_head=0,swich_toe=0;;
        *(data_storage+line)=malloc(sizeof(char)*101);
        if((ptr=strstr(text,*(argv+1)))!=NULL){
            if(Which_is_Bigger(*(argv+1),*(argv+2))==1){
                qtr=ptr;
                for(int i=1;swich_head==0;i++){
                    //printf("wwork\n");
                    *(first+i-1)=*(qtr-i);
                    if((qtr-i)==head){
                        swich_head=1;
                    }
                }
                qtr=(ptr+strlen(*(argv+1)));
                for(int i=0;(swich_toe==0);i++){
                    //printf("work\n");
                    *(last+i)=*(qtr+i);
                    if((qtr+i)==toe){
                        swich_toe=1;
                    }
                }
                //printf("%s\n",Combine(first,*(argv+2),last));
                *(data_storage+line)=Combine(first,*(argv+2),last);
            }
            if(Which_is_Bigger(*(argv+1),*(argv+2))==0){
                qtr=(ptr+strlen(*(argv+1))-1);
                for(int i=0;(head+i)!=ptr;i++){
                    *(first+i)=*(head+i);
                }
                for(int i=0;(toe-i)!=qtr;i++){
                    *(last+i)=*(toe-i);
                }
                //printf("%s%s%s\n",first,*(argv+2),last);
                *(data_storage+line)=Combine(first,*(argv+2),last);
            }
            memset(first,'\0',101);
            memset(last,'\0',101);
        }
        else{
            strcpy(*(data_storage+line),text);
        }
        line++;
        
    }
    for(int i=line-1;i>=0;i--){
        printf("%s\n",*(data_storage+i));
    }
    return 0;
}