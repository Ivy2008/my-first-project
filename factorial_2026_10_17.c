#include<stdio.h>

int factorial(int n ){
    if( n == 0 ){
        return 1 ;
    }else{
        return n*factorial(n - 1);
    }
    //此函数用于计算阶乘
}

int main()
{
    int num ;
    printf("请输入一个非负的整数：\n");
    scanf("%d",&num);
    //读取用户输入的数

    printf("%d的阶乘为%d\n", num ,factorial(num));
    //调用函数，输出目标数的阶乘值

    return 0 ;


}