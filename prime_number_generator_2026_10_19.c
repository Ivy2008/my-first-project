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
    int num ;
    printf("您想生成多少个素数?请输入一个正整数:\n");
    scanf("%d",&num);
    //读取用户输入数据

    if(num <= 0 ){
        printf("您的输入不合法。\n");
        return 0 ;
    }
    //判断用户输入是否合法

    int count = 0 ;              
    //定义进行判断的次数
    
    int x = 2 ;
    for( x = 2 ; count < num ; x++){
        if( is_prime_number(x)){
            printf("%d\n", x);
            count++ ;
        }
    }

    return 0 ;

}