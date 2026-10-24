#include<stdio.h>

void Swap(int *x, int *y)   //此函数用于交换两个变量的值
{
int temp;
temp = *x;
*x = *y;
*y = temp;
}   //注意是通过指针顺着地址找到原变量并交换


void Transpose(int n,int a[n][n]){
    int i = 0 ;
    int j = 0 ;
    for( i=0; i<n ;i++){
        for( j=i+1; j<n; j++){
            Swap(&a[i][j],&a[j][i]);  //将两变量的地址传给函数Swap
            //调用函数，交换第i行j列元素与第j行i列元素,注意只用交换上三角元素，避免又换回去了
        }
    }  

}

int main(void)
{
    int n ;
    printf("Please input a number as the order of matrix\'n\' (not greater than 10):\n");
    scanf("%d",&n);

    if( n<1 || n>10 ){
        return 0 ;
    }       //判断用户输入是否合法

    int Ori[n][n] ;
    //定义原矩阵对应的二维数组
    int i = 0 ;
    int j = 0 ;
    printf("Input a n*n matrix( n<= 10 ):\n");
    for( i=0; i<n ;i++){
        for( j=0; j<n; j++){
            scanf("%d",&Ori[i][j]);
        }
    }   //逐个读入原矩阵元素

    Transpose(n,Ori);    //调用函数，对原矩阵进行转置
    printf("The transposed matrix is:\n");
    for( i=0; i<n ;i++){
        for( j=0; j<n; j++){
            printf("%d",Ori[i][j]);
            if(j<n-1){
                printf(" ");
            }else{
                printf("\n");   //使转置矩阵以n阶矩阵形式打印
            }
            
        }
    }
    return 0 ;
}


