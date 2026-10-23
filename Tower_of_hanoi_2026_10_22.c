#include<stdio.h>

void hanoi(int n ,char source,char auxiliary,char destination){
    if( n == 0 ){
        return ;    //递归终止
    }
    hanoi(n-1,source,destination,auxiliary) ;  
    //将n-1个圆盘从起点柱先移到辅助柱上

    printf("Move disk from %c to %c\n",source,destination);   
    //将起点柱上仅剩的最大的圆盘移到目标柱上，打印该过程

    hanoi(n-1,auxiliary,source,destination) ;
    //将n-1个圆盘从辅助柱移到目标柱上
    
}

int main(void)
{
    int x ;
    scanf("%d",&x);
    //读取圆盘总个数

    hanoi(x,'A','B','C');
    return 0 ;

}