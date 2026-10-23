#include<stdio.h>

int is_prime_number(int num ){
    int i = 2 ;           //定义计算过程中所用变量
    if( num == 1){
        return 0 ;       //先判断是否为特殊情况1
    }else{
        for( i = 2 ; i < num ; i++ ){   //从2到num-1 ,逐次除num取余
                if( num%i == 0 ){
                    return  0 ;
                    break ;       //若能整除说明其不是素数，返回0，终止循环
                }
         }
    }
    return 1 ;
}

int main()
{

    int c,d;
    //printf("请输入两个大于等于2的正整数作为区间的两端,如 3,100 :");
    scanf("%d,%d" ,&c,&d);
    //读取用户输入的区间下限值与上限值


    int x = c;
    int y ;
    y = x+2;
    int count = 0;       //定义素数对的个数

    for( x = c; y < d; x++ ){
        y = x+2 ;
        if( is_prime_number(x) && is_prime_number(y)){
            printf("(%d,%d)",x,y);       //调用函数，当x y 同时为素数时输出素数对
            count++;
        }
    }
    printf("\n");
    printf("%d\n",count);

    return 0 ;

}