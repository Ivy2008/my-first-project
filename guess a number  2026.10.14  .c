#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));
    //生成一个随机数

    int number = rand()%100 + 1 ;
    //定义并处理这个随机数，使之位于0到100以内

    int count = 0 ;
    int a = 0 ;
    //定义次数和输入数字的变量

    printf("我已经想好了一个0到100以内的数。");
    do{
        printf("请猜这个数吧：");
        scanf("%d",&a);
        count++;
        if (a > number){
            printf("你猜的数太大了哟(^-^)");
        }else if(a < number){
                printf("你猜的数太小啦(´▽｀)");
        }
    }while(a != number);
    //用do-while语句判断是否猜中，同时记录猜数次数

    if(count <= 7){
        printf("你真厉害呀！才用了 %d 次就猜中了!\n",count);
    }else{
        printf("你总共用了 %d 次猜中，再试试，还可以更快哟！\n",count);
    }
    //输出次数，并根据次数输入对应语句

    return 0 ;
}