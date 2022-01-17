#include<stdio.h>  
  
  
int main(){  
    int num1;
    int num2;
    while(scanf("%d %d",&num1,&num2)!=EOF){  
        printf("%d\n",(num1+num2));  
    }
    return 0;  
}  