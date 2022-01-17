#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(){

    char text[1000];
    char output[100][1000];
    int times=0;
    while(fgets(text,1000,stdin)!=NULL){
        int i=0;
        int lenth=0;
        int swich=0;
        int check=0;
        while (text[i]!='\n'){
            if(text[i]!=' '){
                output[times][lenth]=text[i];
                lenth++;
                i++;
                swich=0;
                check=1;
            }
            else{
                if(text[i+1]!=' '&&text[i+1]!='\n'&&check!=0){
                    swich=1;
                }
                if(swich==1){
                    output[times][lenth]=text[i];
                    lenth++;
                }
                swich=0;
                i++;
            }
        }
        times++;
    }
    for(int j=0;j<times;j++){
        printf("%s\n",output[j]);
    }
    return 0;
}