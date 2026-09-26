#include<stdio.h>
/* 主函数入口 */
int main()
{
    int a=56;  // 定义整型变量a并初始化为68
    /* 使用if-else语句判断变量a的值是否大于等于60 */
    if(a>=60)
    {
        printf("合格\n");  // 如果条件成立，输出"合格"
    }
    else
    {
        printf("不合格\n");  // 如果条件不成立，输出"不合格"
    }
    return 0;  // 程序正常结束，返回0
}