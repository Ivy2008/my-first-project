#include<stdio.h>

int main ()
{
    int x = 0 ;
    int n = 0 ;

    //初始化变量

    printf ("please enter a number greater than 0 :\n");
    scanf("%d",&x);

    //让用户输入一个大于零的数并读取

    while(x <= 0){
        printf("please re-enter a correct number that meets the requirements : \n");
        scanf("%d",&x);
    }

    //检验用户输入的数字是否符合条件，若不符合则让用户重新输入一个大于零的数并读取
    do{
        n++;
        x/= 10 ;
    }while(x > 0);

    //通过do-while 循环计算出数字的位数

    printf("the digit of the number you enter is :%d\n",n);
    printf("goodbye :)\n");
    return 0 ;
}