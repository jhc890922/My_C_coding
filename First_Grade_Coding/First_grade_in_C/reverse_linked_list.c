#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct data{
    char* word;
    struct data *next;
};

int main(){

    struct data *head;
    head=malloc(sizeof(struct data));
    struct data *current=head;
    current->word=malloc(sizeof(char)*100);
    scanf("%s\n",current->word);
    current->next=NULL;
    char *text;
    int swich=0,times=0;
    text=malloc(sizeof(char)*100);
    while(fgets(text,100,stdin)!=NULL){
        swich=0;
        if(*(text+strlen(text)-1)=='\n'){
            *(text+strlen(text)-1)='\0';
        }
        
        current=head;
        
        while(current!=NULL){
            
            if(strcmp(current->word,text)!=0){
                if(current->next==NULL){
                    current->next=malloc(sizeof(struct data));
                    current=current->next;
                    current->word=malloc(sizeof(char)*100);
                    strcpy(current->word,text);
                    current->next=NULL;
                    swich=1;
                    times++;
                }
                else{
                    current=current->next;
                }
            }
            if(swich==1){
                break;
            }
            
        }
    }
    //printf("work");
    current=head;
    struct data output[times];
    for(int i=0;current!=NULL;i++){
        output[i].word=malloc(sizeof(char)*100);
        strcpy(output[i].word,current->word);
        current=current->next;
    }
    for(int i=times;i>=0;i--){
        printf("%s\n",output[i].word);
    }
    for(int i=0;i<=times;i++){
        printf("%s\n",output[i].word);
        free(output[i].word);
    }
    current=head;
    struct data *temp;
    while(current!=NULL){
        temp=current;
        current=current->next;
        free(temp->word);
        free(temp);
    }
    return 0;
}