#include<stdio.h>

//此函数用于计算参数按规则变换到1所需的总步数
int countSteps(int x){
    int count = 0 ;
    if(x == 1){
        return count ;
    }else{
        if(x%2 == 0){
            x = x/2;    //若为偶数则除以2
            count = countSteps(x)+1 ;   //函数递归，步数加一
        }else{
            x = x*3 + 1;    //若为奇数则乘以3再加1
            count = countSteps(x)+1 ;
        }
        return count ;
    }
}

int main()
{
    int n ;
    printf("请输入一个正整数:\n");
    scanf("%d",&n);
    printf("该数字按规则变换到1所需的总步数为:%d\n",countSteps(n));
    return 0 ;
}