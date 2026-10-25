#include<stdio.h>
#define MAXN 5


typedef struct{     //定义人员信息结构体
    char name[50];
    char sex[50];

    int year;
    int month;
    int day;

    char college[50];
    char post[50];
    char title[50];
}Menber;

Menber Compare_By_Age( Menber a[]){
    Menber oldest = a[0];   //先假设第一个人是最老的
    for( int i=1 ; i<MAXN; i++){      
        if(a[i].year < oldest.year || (a[i].year == oldest.year&&a[i].month < oldest.month) ||(a[i].year == oldest.year&&a[i].month == oldest.month&&a[i].day < oldest.day) ){
            oldest = a[i];
        }   //再遍历数组，通过比较不断更新oldest
    }
    return oldest;
}

int main()
{ 
    Menber men[MAXN];   //定义人员信息结构体数组
    printf("请依次输入每位人员的信息:\n");
    printf("格式如下:张三 男 2000-11-6 计算机学院 学生 班长\n");
    for( int a=0 ;a<MAXN;a++){
        printf("请输入第%d个人的信息:\n",a+1);
        scanf("%s %s %d-%d-%d %s %s %s",men[a].name,men[a].sex,&men[a].year,&men[a].month,&men[a].day,men[a].college,men[a].post,men[a].title);   //读取用户输入的人员姓名
    }
    //读取用户输入的人员信息
    



    Menber res ;   //定义最终结果的结构体数组
    res = Compare_By_Age(men); //调用函数，将比较得出的年龄最大者信息赋给res
    
    printf("年龄最大的人是:\n");

    for(int k=0 ; k<MAXN ;k++){
        if( men[k].year == res.year && men[k].month == res.month && men[k].day == res.day){
            printf("%s\n",men[k].name);     //和原数组比较，看是否有年龄并列最大者，一并打印其名字
        }
    }
    return 0 ;
}