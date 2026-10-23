#include<stdio.h>

int sum_of_proper_divisor( int num ){
    int x = 1 ;
    int result = 0 ;
    if( num == 1){        //首先判断n=1的情况
        result = 1 ;
    }else{
        for( x = 1; x < num; x++){    
            if( num%x == 0 ){     //判断x是否为n的真因数
                result = result + x ;  //累加n的真因数
            }
        }
    }
    return result ;
}

int main()
{
    int n ;
    //printf("请输入一个正整数:\n");
    scanf("%d",&n);

    int a = 1 ;
    int b = 1 ;
    int i ;

    for( a=1 ;a<=n ;a++){
        b = sum_of_proper_divisor( a );     //将a的真因数之和存入b
        i = sum_of_proper_divisor( b );     //将b的真因数之和存入i
        if(i == a && a<b){
            printf("(%d,%d)\n",a,b);    //若i=a,则a与b为亲密数，只打印较小数在前的数对
        }
    }

    return 0 ;
    
}