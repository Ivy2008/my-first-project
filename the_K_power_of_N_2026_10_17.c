#include<stdio.h>

int power(int ba ,int exp){
    int result ;
    //定义最终输出值

    if( ba == 0){
        result = 0;
        }else if( exp == 0){
            result = 1;
        }else{
            int count = exp ;
            result = ba ;
            for( count  = exp ; count != 1;count--){
            result = ba *result;
            }
        }
    return result;
}
//此函数先依次判断底数ba与指数exp是否为0，排除特殊情况后计算并返回结果

int main(){
    int n ,k ;
    printf("请分别输入两个非负整数n与k(n与k不能同时为0):\n");
    scanf("%d %d" ,&n,&k);
    //读取用户输入的底数与指数


    if( n == 0 && k == 0){
        printf("n与k不能同时为0,您的输入不正确。\n");
        return 0 ;
    //判断用户输入是否合法
    }else{
        printf("%d的%d次方为:%d\n", n ,k ,power(n , k));
        //调用函数，打印结果
    }
    return 0 ;
    
}