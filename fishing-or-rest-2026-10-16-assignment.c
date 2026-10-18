#include<stdio.h>

int is_leap(int y){
    return( ( y%4 == 0 && y%100 != 0)|| y%400 == 0);
}
//此函数判断输入年份是否是闰年：能被4整除且不能被100整除，或能被400整除

int days_in_month(int y,int m){
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if( m == 2 && is_leap(y)){
        return 29;
    }else{
        return days[m-1];
    }
}
//此函数根据输入的年份月份判断当月有多少天，若是闰年的2月则返回29天

int main()
{
    int y,m,d;
    //定义用户输入年月日对应的变量

    if(scanf("%4d-%2d-%2d",&y,&m,&d) != 3){
        printf("Invalid input\n");
        return 0 ;
    }
    //读取用户输入的年月日（分别最多输入4位年份，2位月份与日），并判断成功赋值的量的个数是否等于3，若否则显示非法输入

if( y<1990 || m <1 || m>12 || d> days_in_month(y,m)){
    printf("Invalid input\n");
    return 0 ;
}
//判断用户输入的年月日是否合法：年份不能小于1990，月份应在1到12之间，日不应超过当月总天数，若否则显示非法输入

long long total = 0 ;
//定义并初始化输入日期到1990-01-01的总天数

int year,month;
//定义用于下面运算的量


for( int year  = 1990 ; year < y ; year++){
    if(is_leap(year)){
        total += 366 ;
    }else{
        total += 365 ;
    }
}
//计算1990年到输入年份的前一年所经总天数

for( int month = 1 ; month < m ; month++){
    total += days_in_month(y,month);
}
//计算1月到输入月份的前一个月所经总天数

total += d-1;
//计算输入月份当月天数，由于1990-01-01是第零天，最后要减去1

int r = 5 ;
//周期为5

if( total %r == 0 || total %r == 1 || total %r == 2){
    printf("working\n");
}else{
    printf("rest\n");
}
//总天数除以5取余，余数为0，1，2则输出working,反之输出rest

    return 0 ;

}