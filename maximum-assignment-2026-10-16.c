#include<stdio.h>

int Maximum( int num1 , int num2){
    if( num1 > num2 ){
        return num1 ;
    }else{
        return num2 ;
    }
}
//此函数用于比较两个整数的大小

int main()
{
    int a,b;
    printf("请输入两个互不相等的整数：\n");
    scanf("%d %d",&a,&b);
    //读取用户输入的两个整数

    if(a == b){
        printf("您的输入不正确。\n");
        //判断输入是否合法

    }else{
    int result = 0 ;
    result = Maximum(a,b);
    //调用函数，得到最大值
    printf("您输入的这两个数的最大值是：%d\n",result);
    }

    return 0 ;

}