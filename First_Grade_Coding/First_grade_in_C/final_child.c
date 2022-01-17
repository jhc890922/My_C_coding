#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
size_t my_strlen(char *s){
    char* ptr=s;
    int num=0;
    while(*(ptr+num)){
        num++;
    }
    return num;
}

char *my_strcat(char *s, char *t){
    int num_s=my_strlen(s);
    int num_t=my_strlen(t);
    char* ptr=s;
    char* qtr=t;
    for(int i=0;i<num_t;i++){
        *(ptr+num_s+i)=*(qtr+i);
    }
    return s;
}

char *my_strstr(char *haystack, char *needle){
    char* ptr=haystack;
    char* qtr=needle;
    int num=0;
    int check;
    while(*(ptr+num)){
        if(*(ptr+num)!=*(qtr)){
            num++;
        }
        else{
            for(check=0;*(qtr+check);){
                if(*(ptr+num+check)==*(qtr+check)){
                    check++;
                }
                
                else{
                    num++;
                    break;
                }
                if(check==my_strlen(needle)){
                    return (ptr+num);
                }
            }
        }
    }
    return NULL;
}
int main(){

    char* text;
    text=malloc(sizeof(char)*64);
    char* all_word;
    char* ptr;
    all_word=malloc(sizeof(char)*8192);
    char* mama;
    mama=malloc(sizeof(char)*8192);
    while(fgets(text,64,stdin)!=NULL){
        my_strcat(all_word,text);
    }
    if((ptr=my_strstr(all_word,"Mama"))!=NULL){
        for(int i=0;*(ptr+i);i++){
            *(mama+i)=*(ptr+i);
        }
        printf("[len]:\n%ld\n\n",my_strlen(mama));
        printf("[content]:\n%s\n",mama);
    }
    else{
        printf("[len]:\n%ld\n\n",my_strlen(mama));
        printf("[content]:\n(null)\n");
    }
    return 0;
}
