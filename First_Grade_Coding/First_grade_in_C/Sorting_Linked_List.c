#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct data{
    char *word;
    struct data *next;
};

int  cmp(const void* a,const void* b){
    return strcmp(((struct data*)a)->word,((struct data *)b)->word);
}

int main(){
    struct data *head;
    head=malloc(sizeof(struct data));
    struct data *current;
    head->next=NULL;
    //current=malloc(sizeof(struct data));
    current=head;
    current->word=malloc(sizeof(char)*1024);
    //current->next=malloc(sizeof(struct data));
    current->next=NULL;
    char text[1024];
    int times=0;
    while(fgets(text,1024,stdin)!=NULL){
        current=head;
        while(strcmp(current->word,text)!=0){
            if(current->next!=NULL){
                //printf("+++%s",current->word);
                current=current->next;
            }
            else{
                strcpy(current->word,text);
                current->next=malloc(sizeof(struct data));
                current=current->next;
                current->word=malloc(sizeof(char)*1024);
                current->next=NULL;
                times++;
                //printf("%d\n",times);
                break;
            }
        }
        //printf("work\n");
    }
   // printf("work");
    current=head;
    struct data output[times];
    for(int i=0;current->next!=NULL;i++){
        output[i].word=malloc(sizeof(char)*1024);
        strcpy(output[i].word,current->word);
        current=current->next;
    }
    qsort(output,times,sizeof(struct data),cmp);
    for(int i=0;i<times;i++){
        printf("%s",output[i].word);
    }
    return 0;

}