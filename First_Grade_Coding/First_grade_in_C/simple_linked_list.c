#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct data{
    int wordcount;
    char* word;
    struct data *next;
};

int main(){

    struct data *head;
    head=malloc(sizeof(struct data));
    struct data *current=head;
    current->word=malloc(sizeof(char)*100);
    
    scanf("%s\n",current->word);
    current->wordcount=1;
    current->next=NULL;
    char *text;
    int swich=0;
    text=malloc(sizeof(char)*100);
    while(fgets(text,100,stdin)!=NULL){
        
        swich=0;
        if(*(text+strlen(text)-1)=='\n'){
            *(text+strlen(text)-1)='\0';
        }
        
        current=head;
        
        while(current!=NULL){
            if(swich==1){
                break;
            }
            if(strcmp(current->word,text)!=0){
                if(current->next==NULL){
                    current->next=malloc(sizeof(struct data));
                    current=current->next;
                    current->word=malloc(sizeof(char)*100);
                    strcpy(current->word,text);
                    current->wordcount=1;
                    current->next=NULL;
                    swich=1;
                }
                else{
                    current=current->next;
                }
            }
            else if(strcmp(current->word,text)==0){
                current->wordcount++;
                swich=1;
            }
            
        }
    }
    current=head;
    while(current!=NULL){
        if(*current->word!='\0'){
            printf("%s %d\n",current->word,current->wordcount);
            current=current->next;
        }
        else{
            current=current->next;
        }
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