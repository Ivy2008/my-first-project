#include<stdio.h>

int low_com_mul( int num1 ,int num2){
    int x = 1;
    for(  x = 1 ; x%num1 != 0 || x%num2 != 0 ; ){
        x++;
    }
    return x ;
}

int main()
{
    int a,b ;
    printf("请输入两个正整数：\n");
    scanf("%d %d",&a,&b);
    //读取用户输入的两个数

    int result ;
    result = low_com_mul(a,b);
    //调用函数，计算最小公倍数
    printf("您输入的这两个数的最小公倍数为：%d\n",result);
    return 0 ;
}