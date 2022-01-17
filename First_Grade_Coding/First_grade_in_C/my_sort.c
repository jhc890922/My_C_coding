#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int cmp(const void* a,const void* b){
    //printf("--%s--%s\n",(char* )a,(char* )b);
    return strcmp(*(char** )a,*(char** )b);
}

int cmp_n(const void* a,const void* b){
    //printf("--%d--%d\n",atoi((char*) a),atoi((char*) b));
    return atoi(*(char**)a)-atoi(*(char**)b);
}

int main(int argc,char** argv){
    char text[8192];
    char** data;
    int times=0;
    data=malloc(sizeof(char*)*21000);
    for(int i=1;i<argc;i++){
    if((argc!=1)&&(strcmp(*(argv+i),"-d")!=0)&&(strcmp(*(argv+i),"-n")!=0)){
        printf("usage: mysort [-dn]\n");
        return 0;
    }
    }
    while(fgets(text,8192,stdin)!=NULL){
        if(text[strlen(text)-1]=='\n'){
            text[strlen(text)-1]='\0';
        }
        *(data+times)=malloc(sizeof(char)*strlen(text)+1);
        strcpy(*(data+times),text);
        times++;
        
    }
    //data=realloc(data,sizeof(char*)*times);
    //char output[times][8192];
    /*for(int i=0;i<times;i++){
            strcpy(output[i],*(data+i));
            //printf("%s\n",output[i]);
        }*/
        //printf("work");
        qsort(data,times,sizeof(char*),cmp);
    //printf("work\n");
    int swich=0;
    for(int k=1;k<argc&&argc>1;k++){

        if(strcmp(*(argv+k),"-n")==0){
            qsort(data,times,sizeof(char*),cmp_n);
            swich=0;
        }
        if(strcmp(*(argv+k),"-d")==0){
            swich=1;
        }
        
    }
    if(swich==1){
        for(int i=times-1;i>=0;i--){
                printf("%s\n",*(data+i));
                //free(*(data+i));
            }
        for(int i=0;i<times;i++){
                free(*(data+i));
            }
        return 0; 
    }
    for(int i=0;i<times;i++){
        printf("%s\n",*(data+i));
        free(*(data+i));
    }
return 0;
}