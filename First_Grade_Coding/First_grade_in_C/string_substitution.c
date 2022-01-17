
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
 
int main(int argc,char** argv){
    char* text;
    text=malloc(sizeof(char)*1000);
    char* ptr;
    char* last;
    char* first;
    first=malloc(sizeof(char)*1000);
    last=malloc(sizeof(char)*1000);
    while(fgets(text,1000,stdin)!=NULL){
        while((ptr=strstr(text,*(argv+1)))!=NULL){
            
            for(int i=0;(text+i)!=ptr;i++){
                *(first+i)=*(text+i);
            }
            for(int i=0;*(ptr+i)!='\n';i++){
                *(last+i)=*(ptr+strlen(*(argv+1))+i);
            }
            //printf("work\n");
            memset(text,'\0',1000);
            for(int i=0;(text+i)!=ptr;i++){
                *(text+i)=*(first+i);
            }
            for(int i=0;i<strlen(*(argv+2));i++){
                *(ptr+i)=*(*(argv+2)+i);
            }
            
            for(int i=0;i<strlen(last);i++){
                *(ptr+i+strlen(*(argv+2)))=*(last+i);
            }
            
            
            ptr++;
            //*(text+strlen(text))='\n';
            memset(last,'\0',1000);
            memset(first,'\0',1000);
            //printf("1.%s.1\n",last);
        }
        
        printf("%s",text);
        memset(text,'\0',1000);
    }
    return 0;
}


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
 
int main(int argc,char** argv){
    char* text;
    text=malloc(sizeof(char)*1000);
    char* ptr;
    char* last;
    char* first;
    first=malloc(sizeof(char)*1000);
    last=malloc(sizeof(char)*1000);
    while(fgets(text,1000,stdin)!=NULL){
        while((ptr=strstr(text,*(argv+1)))!=NULL){
            
            for(int i=0;(text+i)!=ptr;i++){
                *(first+i)=*(text+i);
            }
            for(int i=0;*(ptr+i)!='\n';i++){
                *(last+i)=*(ptr+strlen(*(argv+1))+i);
            }
            //printf("work\n");
            memset(text,'\0',1000);
            for(int i=0;(text+i)!=ptr;i++){
                *(text+i)=*(first+i);
            }
            for(int i=0;i<strlen(*(argv+2));i++){
                *(ptr+i)=*(*(argv+2)+i);
            }
            
            for(int i=0;i<strlen(last);i++){
                *(ptr+i+strlen(*(argv+2)))=*(last+i);
            }
            
            
            ptr++;
            //*(text+strlen(text))='\n';
            memset(last,'\0',1000);
            memset(first,'\0',1000);
            //printf("1.%s.1\n",last);
        }
        
        printf("%s",text);
        memset(text,'\0',1000);
    }
    return 0;
}

