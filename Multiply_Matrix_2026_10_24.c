#include<stdio.h>
#define ROW 2
#define COL 3

// 函数功能：计算矩阵相乘之积，结果存于二维数组c中
int MultiplyMatrix(int a[ROW][COL], int b[COL][ROW], int c[ROW][ROW] )
{
	int i, j, k; 
	for( i=0; i<ROW; i++)
	{
		for( j=0; j<ROW; j++)	//对数组进行遍历
		{
			c[i][j]= 0 ;
			for( k=0; k<COL; k++)
			{
				c[i][j] += a[i][k]*b[k][j] ;	
				//根据矩阵乘法法则，矩阵c第i行j列元素等于矩阵a第i行各元素与矩阵b第j列各元素对应乘积之和
			}
		}
	}
	return c[ROW][ROW] ;
}        

// 函数功能：输出矩阵a中的元素
void PrintMatrix(int a[ROW][ROW])
{
	int i, j;
	for( i=0; i<ROW; i++)
	{
        for( j=0; j<ROW; j++){
            printf("%d",a[i][j]);
            	if(j<ROW-1){
                	printf(" ");
            	}else{
                	printf("\n");   //使矩阵以ROW阶矩阵形式打印
            	}
			}
	}
}


int main(void)
{
	int a[ROW][COL], b[COL][ROW], c[ROW][ROW], i, j;
	printf("Input 2*3 matrix a:\n");
	for( i=0; i<ROW; i++)
	{
		for( j=0; j<COL; j++)
		{
			scanf("%d", &a[i][j]);		//读取用户输入的矩阵a
		}
	}
	printf("Input 3*2 matrix b:\n");
	for( i=0; i<COL; i++)
	{
		for( j=0; j<ROW; j++)
		{
			scanf("%d", &b[i][j]);		//读取用户输入的矩阵b
		}
	}
	MultiplyMatrix(a,b,c);		
	//调用函数，求出两矩阵乘积

	printf("Results:\n");
	PrintMatrix(c);
	//调用函数，打印结果矩阵

	return 0;
}





