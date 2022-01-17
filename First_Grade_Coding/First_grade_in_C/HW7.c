#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<unistd.h>
#define maxvalue 10000000
int data[maxvalue];
int temp[maxvalue];

void HeapAdjust(int a[],int s,int m){	//一次篩選的過程
    int rc,j;
    rc=a[s];
    for(j=2*s;j<=m;j=j*2)	//通過循環沿較大的孩子結點向下篩選
    {
        if(j<m&&a[j]<a[j+1]) j++;	//j爲較大的記錄的下標
        if(rc>a[j]) break;
        a[s]=a[j];s=j;
    }
    a[s]=rc;	//插入
}
void HeapSort(int a[],int n)
{
    int temp,i,j;
    for(i=n/2;i>0;i--)//通過循環初始化頂堆
    {
        HeapAdjust(a,i,n);
    }
    for(i=n;i>0;i--)
    {
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;//將堆頂記錄與未排序的最後一個記錄交換
        HeapAdjust(a,1,i-1);//重新調整爲頂堆
    }
}
int main(){

    struct timeval start;
    struct timeval end;
    long int diff; 
    srand(time(NULL));
    
    for(int i=0;i<10000000;i++){
        data[i]=rand();
        //printf("%d\n",data[i]);
    }
    gettimeofday(&start,NULL);
    //printf("%d\n",start.tv_usec);
    HeapSort(data,10000000);
    gettimeofday(&end,NULL);
    //printf("%d\n",end.tv_usec);
    diff=1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec;
    printf("Used time : %ld\n",diff);
    return 0;
}