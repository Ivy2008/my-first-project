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
    int x ;
    printf("请输入一个正整数:\n");
    scanf(" %d", &x);      //读取用户输入数据
    if( x <= 0){
        printf("您的输入不合法。\n");
        return 0 ;
    }      
    //判断用户输入是否合法

    if( is_prime_number(x)){
        printf("%d是素数\n",x);
    }else{
        printf("%d不是素数\n",x);
    }
    //调用函数，判断目标数是否为素数

    return 0 ;
}
