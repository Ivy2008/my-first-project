#include<stdio.h>

int main()
{
    int result,number ;
    char op ;
    //定义结果，运算过程中的数，运算符分别对应的变量

    printf("请输入算式  不要带空格：");
    scanf("%d",&result);
    //读取第一个数字

    while(1){
        scanf("%c",&op);
        //读取第一个运算符

        if(op == '='){
            break;
        //运算符为'='则直接跳出循环

        }else  if( op!='+'  && op!='-' &&  op!= '*' &&  op!= '/'){
            printf("错误的运算符:%c\n",op);
            return 0 ;
        //判断运算符是否合法,若不合法，则打印该运算符并退出运行
        }
        scanf("%d",&number);
        if( op == '/'){
            if(number == 0){
                printf("除数不能等于0");
                return 0 ;
            }else{
                result /= number;
            }
        }
        //判断除数是否等于0，若是则退出进程，若不是则进行运算

        switch(op){
            case'+':
            result += number;
            break;

            case'-':
            result -= number;
            break;
          
            case'*':
            result *= number;
            break;

            default:
            break;
        }
        //根据运算符的类型分别进行运算
    }
    printf("%d",result);
    return 0 ;
}