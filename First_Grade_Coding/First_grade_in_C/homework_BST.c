#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
//這一定錯


struct data{
    char* word;
    int word_count;
    struct data *left;
    struct data *right;
};
struct save{
    char word[100];
    int word_count;
};

void b(struct data *aa){
    if(aa!=NULL){
        b(aa->left);
        printf("%d %s",aa->word_count,aa->word);
        b(aa->right);
    }
}

void fre(struct data *aa){
    if(aa!=NULL){
        fre(aa->left);
        fre(aa->right);
        free(aa->word);
        free(aa);
    }
}

int  cmp(const void* a,const void* b){
    return ((struct save*)b)->word_count-((struct save*)a)->word_count;
}

int main(){
    char* insert;
    insert=malloc(sizeof(char)*100);
    struct data *head;
    struct data *current;
    struct save output[1000];
    int swich=0,swich2=0,times=0;
    char minus[100];
    head=malloc(sizeof(struct data));
    current=head;
    current->word=malloc(sizeof(char)*100);
    current->left=NULL;
    current->right=NULL;
    while(fgets(insert,100,stdin)!=NULL){
        int swich3=0;
        current=head;
        if(swich==0){
            strcpy(current->word,insert);
            strcpy(output[times].word,insert);
            output[times].word_count=0;
            times++;
            current->word_count=0;
            swich++;
        }
        if(*insert=='-'){
            for(int i=1;i<strlen(insert);i++){
                minus[i-1]=*(insert+i);
                for(int i=0;i<=times;i++){
                    if(strcmp(output[i].word,minus)==0){
                        output[i].word_count--;
                        break;
                    }
                }
            }
            swich3=1;
        }
        while(current!=NULL){
            if(swich3==1){
                strcpy(insert,minus);
            }
            if(strcmp(insert,current->word)==0&&swich3==0){
                current->word_count++;
                for(int i=0;i<=times;i++){
                    if(strcmp(output[i].word,insert)==0){
                        output[i].word_count++;
                        break;
                    }
                }
                break;
            }
            else if(strcmp(insert,current->word)==0&&swich3==1){
                current->word_count--;
                break;
            }
            else if(strcmp(insert,current->word)>0){
                if(current->right==NULL){
                    current->right=malloc(sizeof(struct data));
                    current=current->right;
                    current->word=malloc(sizeof(char)*100);
                    strcpy(current->word,insert);
                    current->word_count=1;
                    current->right=NULL;
                    current->left=NULL;
                    swich2=1;
                    strcpy(output[times].word,current->word);
                    output[times].word_count=1;
                    times++;
                }
                else if(current->right!=NULL){
                    current=current->right;
                }
            }
            else if(strcmp(insert,current->word)<0){
                if(current->left==NULL){
                    current->left=malloc(sizeof(struct data));
                    current=current->left;
                    current->word=malloc(sizeof(char)*100);
                    strcpy(current->word,insert);
                    current->word_count=1;
                    current->left=NULL;
                    current->right=NULL;
                    swich2=1;
                    strcpy(output[times].word,current->word);
                    output[times].word_count=1;
                    times++;
                }
                else if(current->left!=NULL){
                    current=current->left;
                }
            }
            if(swich2==1){
                swich2=0;
                break;
            }
        }
    }
    current=head;
    printf("Inorder traversal:\n");
    b(current);
    printf("\nCount sorting:\n");
    struct save temp;
    qsort(output,times,sizeof(struct save),cmp);
    for(int i=0;i<times;i++){
        for(int j=i;j<times;j++){
            if((output[i].word_count==output[j].word_count)&&(strcmp(output[i].word,output[j].word))>0){
                temp=output[i];
                output[i]=output[j];
                output[j]=temp;
            }
        }
    }
    for(int i=0;i<=(times);i++){
        if(strcmp(output[i].word,"\0")!=0){
            printf("%d %s",output[i].word_count,output[i].word);
        }
    }
    fre(current);
    return 0;
}