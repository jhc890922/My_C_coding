#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct scoreboard{
    int chinese;
    int english;
    int math;
    int science;
    int social;
    int total;
};

void bubble_sort(struct scoreboard a[],int num){
    struct scoreboard temp;
    for(int i=0;i<num;i++){
        for(int j=i;j<num;j++){
            if(a[i].total<a[j].total){
                temp.chinese=a[i].chinese;
                //printf("||%d||\n",temp.chinese);
                a[i].chinese=a[j].chinese;
                a[j].chinese=temp.chinese;
                temp.english=a[i].english;
                a[i].english=a[j].english;
                a[j].english=temp.english;
                temp.math=a[i].math;
                a[i].math=a[j].math;
                a[j].math=temp.math;
                temp.science=a[i].science;
                a[i].science=a[j].science;
                a[j].science=temp.science;
                temp.social=a[i].social;
                a[i].social=a[j].social;
                a[j].social=temp.social;
                temp.total=a[i].total;
                a[i].total=a[j].total;
                a[j].total=temp.total;
            }
        }
    }
}

int main(){
    struct scoreboard student[1000];
    char text[1024];
    //text=malloc(sizeof(char)*1024);
    char score[5][100];
    /*char score0[3];
    char score1[3];
    char score2[3];
    char score3[3];
    char score4[3];*/
    memset(score,'\0',sizeof(score));
    int num=0;
    while(fgets(text,1024,stdin)!=NULL){
        int j=0;
        int k=0;
        int swich=0;
        for(int i=0;text[i]!='\n';i++){
            if((text[i]>='0')&&(text[i]<='9')){
                if(swich==1){
                    j++;
                    swich=0;
                }
                score[j][k]=text[i];
                //printf("%c",*(text+i));
                //printf("%d\n",k);
                k++;
            }
            else{
                k=0;
                //printf("%d",j);
                swich=1;
            }
            //printf("%s|\n",score[j]);
        }
        //printf("-----------\n");
       /* strncpy(score1,score[1],3);
        strncpy(score2,score[2],3);
        strncpy(score3,score[3],3);
        strncpy(score4,score[4],3);
        strncpy(score0,score[0],3);*/
        student[num].chinese=atoi(score[0]);
        //printf("%d\n",student[num].chinese);
        student[num].english=atoi(score[1]);
        student[num].math=atoi(score[2]);
        student[num].science=atoi(score[3]);
        student[num].social=atoi(score[4]);
        
        student[num].total=(student[num].chinese+student[num].english+student[num].math+student[num].science+student[num].social);
        num++;
        //printf("%d\n",num);
        memset(score,'\0',sizeof(score));
        memset(text,'\0',1024);
    }
    bubble_sort(student,num);
    for(int i=0;i<num;i++){
        printf("%d %d %d %d %d\n",student[i].chinese,student[i].english,student[i].math,student[i].science,student[i].social);
    }
    return 0;
}