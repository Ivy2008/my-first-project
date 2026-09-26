#include <stdio.h>
int main()
{
    int price =0 ;  //定义金额变量
    int amount =0 ; //定义票面变量
    printf("请输入金额(元）：");
    scanf("%d",&price);
    printf("请输入票面（元）：");
    scanf("%d",&amount);
    int change = amount - price ; //计算找零
    printf("找您%d元\n",change);
    return 0 ;
}