#include<stdio.h>
#include<string.h>

typedef struct{        //定义结构体数组
    char day[50];   //保证容纳足够长的字符串
    int number;
}Week;


int FindByDay( const Week we[] , int n , const char *Day){  //注意对数组只读不写
    int i = 0;
    for(i= 0;i <n;i++){ 
        if(strcmp(we[i].day,Day) == 0){     //逐一比较输入的字符串与各天的英文
            return we[i].number ;       //配对成功即返回对应的数字
        }
    }
    return -1 ;
}

int main(void)
{
    Week we[] = {
    {"Sunday",0},
    {"Monday",1},
    {"Tuesday",2},
    {"Wednesday",3},
    {"Thursday",4},
    {"Friday",5},
    {"Saturday",6},     //初始化数组
    };

    int seq ;
    char day[50];
    int n = 7 ;
    
    printf("Input the day:\n");
    scanf("%s",day);
    seq = FindByDay(we,n,day);  //调用函数，将对应数字存入变量seq



    if( seq<0){
        printf("Wrong Input.\n");
    }else{
        printf("%d\n",seq);
    }
    return 0 ;

}


