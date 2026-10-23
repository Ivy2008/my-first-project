#include<stdio.h>

int sum_of_proper_divisor( int n ){
    int x = 1 ;
    int result = 0 ;
    if( n == 1){        //首先判断n=1的情况
        result = 1 ;
    }else{
        for( x = 1; x < n; x++){    
            if( n%x == 0 ){     //判断x是否为n的真因数
                result = result + x ;  //累加n的真因数
            }
        }
    }
    return result ;
}

int main()
{
    int a ;
    scanf("%d",&a);
    printf("%d\n", sum_of_proper_divisor(a));
    return 0 ;

}