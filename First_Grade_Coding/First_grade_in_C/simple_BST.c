#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct data{
    char* word;
    struct data *left;
    struct data *right;
};

void inorder(struct data *a){
    if(a!=NULL){
        inorder(a->left);
        printf("%s\n",a->word);
        inorder(a->right);
    }
}
void preorder(struct data *a){
    if(a!=NULL){
        printf("%s\n",a->word);
        preorder(a->left);
        preorder(a->right);
    }
}
void postorder(struct data *a){
    if(a!=NULL){
        postorder(a->left);
        postorder(a->right);
        printf("%s\n",a->word);
    }
}
void fre(struct data *a){
    if(a!=NULL){
        fre(a->left);
        fre(a->right);
        free(a->word);
        free(a);
    }
}

int main(int argc,char** argv){
    
    struct data *head;
    head=malloc(sizeof(struct data));
    struct data *current=head;
    current->word=malloc(sizeof(char)*100);
    memset(current->word,'\0',100);
    current->left=NULL;
    current->right=NULL;
    char text[100];
    scanf("%s\n",text);
    strcpy(current->word,text);
    while(fgets(text,100,stdin)!=NULL){
        if(text[strlen(text)-1]=='\n'){
            text[strlen(text)-1]='\0';
        }
        current=head;
        while(current!=NULL){
            if(strcmp(text,current->word)>0){
                if(current->right==NULL){
                    current->right=malloc(sizeof(struct data));
                    current=current->right;
                    current->word=malloc(sizeof(char)*100);
                    strcpy(current->word,text);
                    current->left=NULL;
                    current->right=NULL;
                }
                else{
                    current=current->right;
                }
            }
            else if(strcmp(text,current->word)<0){
                if(current->left==NULL){
                    current->left=malloc(sizeof(struct data));
                    current=current->left;
                    current->word=malloc(sizeof(char)*100);
                    strcpy(current->word,text);
                    current->left=NULL;
                    current->right=NULL;
                }
                else{
                    current=current->left;
                }
            }
            else{
                break;
            }
        }
    }
    current=head;
    if(strcmp(*(argv+1),"-p")==0){
        preorder(current);
    }
    if(strcmp(*(argv+1),"-P")==0){
        postorder(current);
    }
    if(strcmp(*(argv+1),"-i")==0){
        inorder(current);
    }
    fre(current);
    return 0;
}