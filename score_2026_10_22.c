#include<stdio.h>
#define MAXN 40

long long array_sum(const int a[],int n){   //对于数组只读不写
    long long  res = 0 ;    
    int i = 0 ;
    for( i = 0; i<n; i++){
        res += a[i];
    }
    return res ;    //此函数用于计算数组中前n个数据的总和
}


double array_average(const int a[],int n){
    if(n == 0){
        return 0.0 ;
    }else{
        double res = 0.0;
        res = (double)array_sum(a,n)/n ;  //调用求总和的函数,注意类型转换
        return res ;    //此函数用于计算数组中前n个数据的平均值
    }
}


int main()
{
    int score[MAXN];
    int n = 0 ;
    int x ;
    printf("请输入学生某门课的成绩(最多不超过40人),当输入为负值时,表示输入结束:\n");
    while(n<MAXN && scanf("%d",&x) == 1 && x >= 0 ){        //只有当输入值非负，数据总个数不超过MAXN时才会逐个读取，存入数组
        score[n] = x ;
        n++ ;
    }

    if( n == 0){
        return 0 ;
    }else{
        double aver = array_average(score,n);  //调用求平均值的函数
    
        int number = 0 ;
        int k = 0 ;

        for( k=0; k<n;k++){
            if(score[k]> aver){     //逐个比较数组元素与平均值
                number++;
            }
        }
        printf("这个班的平均分为:%lf\n",aver);
        printf("这个班分数高于平均分的人数为:%d\n",number);

    }
    return 0 ;

}