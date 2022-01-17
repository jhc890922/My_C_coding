#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  

int main(){

    int k=0;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int num=0;
        scanf("%d",&num);
        
        int check_ary[num+1];
        memset(check_ary,0,num);

        for(int max = num-1; max>0;max--){
            printf("check\n");
            int circular_cnt = max;
            int found = 0;
            for(int count = 0;count<num;count++){
                while(check_ary[circular_cnt] == 1){    
                    circular_cnt++;
                    if(circular_cnt>num){
                        circular_cnt-=num;
                    }
                }
                if(check_ary[circular_cnt] == 0){
                    check_ary[circular_cnt] = 1;
                    circular_cnt+=max;
                    if(circular_cnt>num){
                        circular_cnt-=num;
                    }
                }
                if(circular_cnt == num && count == (num-1)){
                    found=1;
                    break;
                }
                else if(circular_cnt == num && count != (num-1)){
                    break;
                }
            }

            if(found == 1){
                printf("%d\n",max);
                break;
            }


        }

    }
}
